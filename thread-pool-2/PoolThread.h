#pragma once

#include <vector>
#include <deque>
#include <memory>
#include <boost/thread.hpp>


class PoolThread;
 



// our worker thread objects
class Worker {
public:
    Worker(PoolThread &s) : pool(s) { }
    void operator()();
private:
    PoolThread &pool;
};




template<class T>
class Result {
    struct ResultImpl {
        ResultImpl() : value(T()), available(false) { }
        T value;
        bool available;
        boost::mutex lock;
        boost::condition_variable cond;
    };

public:
    Result() : impl(new ResultImpl()) { }

    bool available() const
    {
        std::unique_lock<boost::mutex> ul(impl->lock);
        return impl->available;
    }

    void wait()
    {
        if(!impl)
            return;
        boost::unique_lock<boost::mutex> ul(impl->lock);
        if(impl->available)
            return;
        impl->cond.wait(ul);
    }

    void signal() const
    {
        boost::unique_lock<boost::mutex> ul(impl->lock);
        impl->available = true; impl->cond.notify_all();
    }

    bool valid() const
    { 
        boost::unique_lock<boost::mutex> ul(impl->lock);
        return static_cast<bool>(impl);
    }

    T& get()
    { 
        wait(); 
        return impl->value;
    }

    void set(T v) const
    {
        boost::unique_lock<boost::mutex> ul(impl->lock); 
        impl->value = v; 
    }
  
private:
    std::shared_ptr<ResultImpl> impl;
};




template<>
class Result<void> {
    struct ResultImpl {
        ResultImpl() : available(false) {  }
        bool available;
        boost::mutex lock;
        boost::condition_variable cond;
    };

public:
    Result() : impl(new ResultImpl()) { }

    bool available() const
    {
        boost::unique_lock<boost::mutex> ul(impl->lock);
        return impl->available;
    }

    void wait()
    {
        if(!impl)
            return;
        boost::unique_lock<boost::mutex> ul(impl->lock);
        if(impl->available)
            return;
        impl->cond.wait(ul);
    }

    void signal() const
    {
        boost::unique_lock<boost::mutex> ul(impl->lock);
        impl->available = true; impl->cond.notify_all();
    }

    bool valid() const
    { 
        boost::unique_lock<boost::mutex> ul(impl->lock);
        return static_cast<bool>(impl);
    }

private:
    std::shared_ptr<ResultImpl> impl;
};




// the actual thread pool
class PoolThread {
public:
    PoolThread(size_t);

    template<class T, class F>
    Result<T> enqueue(F f);

    ~PoolThread();

private:
    friend class Worker;

    // need to keep track of threads so we can join them
    std::vector< boost::thread > workers;
    // the task queue
    std::deque< std::function<void()> > tasks;
    
    // synchronization
    boost::mutex queue_mutex;
    boost::condition_variable condition;
    bool stop;
};
 



void Worker::operator()()
{
    std::function<void()> task;
    while(true)
    {
        {
            boost::unique_lock<boost::mutex> lock(pool.queue_mutex);
            while(!pool.stop && pool.tasks.empty())
                pool.condition.wait(lock);
            if(pool.stop)
                return;
            task = pool.tasks.front();
            pool.tasks.pop_front();
        }
        task();
    }
}
 



// the constructor just launches some amount of workers
PoolThread::PoolThread(size_t threads)
    :   stop(false)
{
    for(size_t i = 0;i<threads;++i)
        workers.push_back(boost::thread(Worker(*this)));
}

template<class T, class F>
struct CallAndSet {
    void operator()(const Result<T> &res, const F f)
    {
        res.set(f());
        res.signal();
    }
};




template<class F>
struct CallAndSet<void,F> {
    void operator()(const Result<void> &res, const F &f)
    {
        f();
        res.signal();
    }
};
 



// add new work item to the pool
template<class T, class F>
Result<T> PoolThread::enqueue(F f)
{
    Result<T> res;
    {
        boost::unique_lock<boost::mutex> lock(queue_mutex);
        tasks.push_back(std::function<void()>(
        [f,res]()
        {
            CallAndSet<T,F>()(res, f);
        }));
    }
    condition.notify_one();
    return res;
}
 



// the destructor joins all threads
PoolThread::~PoolThread()
{
    stop = true;
    condition.notify_all();
    for(size_t i = 0;i<workers.size();++i)
        workers[i].join();
}
