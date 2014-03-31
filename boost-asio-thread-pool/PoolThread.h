#pragma once

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <vector>


template< size_t countThread >
class PoolThread;




/**
* Рабочий для выполнения задач в потоках.
*/
template< size_t countThread >
class WorkerThread {
public:
    typedef PoolThread< countThread >  poolThread_t;




public:
    inline WorkerThread( poolThread_t& pool ) : mPool( pool ) { }




    void operator()();




private:
    poolThread_t&  mPool;
};








/**
* Пул потоков.
*/
template< size_t countThread >
class PoolThread {
public:
    typedef WorkerThread< countThread >  workerThread_t;




public:
    PoolThread();




    ~PoolThread();




    /**
    * Добавляет новое задание в пул.
    */
    template< class F >
    void enqueue( F );




private:
    /**
    * Сохраняем рабочих, чтобы могли при необходимости присоединиться к ним.
    */
    typedef std::unique_ptr< boost::thread >  thread_ptr;
    std::vector< thread_ptr >  mWorkerSet;
 
    /**
    * Обёртка boost::asio.
    */
    boost::asio::io_service        mService;
    boost::asio::io_service::work  mWorking;

    friend class workerThread_t;
};








#include "PoolThread.inl"
