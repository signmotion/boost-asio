#include "../include/stdafx.h"
#include "../include/PoolThread.h"


template< size_t countThread >
void WorkerThread< countThread >::operator()() {
    mPool.mService.run();
}




template< size_t countThread >
PoolThread< countThread >::PoolThread() :
    mWorking( mService )
{
    // создаём нескольких рабочих в потоках
    for (size_t i = 0; i < countThread; ++i) {
        mWorkerSet.push_back( thread_ptr(
            new boost::thread( workerThread_t( *this ) )
        ) );
    }
}




template< size_t countThread >
PoolThread< countThread >::~PoolThread() {
    mService.stop();
    for (auto itr = mWorkerSet.cbegin(); itr != mWorkerSet.cend(); ++itr) {
        ( *itr )->join();
    }
}




template< size_t countThread >
template< class F >
void PoolThread< countThread >::enqueue( F fn ) {
    mService.post( fn );
}
