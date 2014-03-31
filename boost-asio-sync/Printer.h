#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
#include "Console.h"


class Printer {
public:
    inline Printer(
        boost::asio::io_service& io
    ) :
        mStrand( io ),
        mTimerA( io, DELTA ),
        mTimerB( io, DELTA ),
        mCount( 0 )
    {
        mTimerA.async_wait( boost::bind( &Printer::printA, this ) );
        mTimerB.async_wait( boost::bind( &Printer::printB, this ) );
    }




    inline ~Printer() {
        std::cout << "Final count is " << mCount << "\n";
    }




    inline void printA() {
        if (mCount >= 10) {
            return;
        }
        {
            //boost::mutex::scoped_lock  lock( mtxOStream );
            mConsole << "TimerA " << mCount << "\n";
        }
        {
            boost::mutex::scoped_lock  lock( mtxCount );
            ++mCount;
        }
        mTimerA.expires_at( mTimerA.expires_at() + DELTA );
        mTimerA.async_wait( mStrand.wrap( boost::bind( &Printer::printA, this ) ) );
    }




    inline void printB() {
        if (mCount >= 10) {
            return;
        }
        {
            //boost::mutex::scoped_lock  lock( mtxOStream );
            mConsole << "TimerB " << mCount << "\n";
        }
        {
            boost::mutex::scoped_lock  lock( mtxCount );
            ++mCount;
        }
        mTimerB.expires_at( mTimerB.expires_at() + DELTA );
        mTimerB.async_wait( mStrand.wrap( boost::bind( &Printer::printB, this ) ) );
    }




private:
    boost::asio::strand  mStrand;
    boost::asio::deadline_timer  mTimerA;
    boost::asio::deadline_timer  mTimerB;
    int  mCount;

    static const boost::posix_time::seconds  DELTA;

    mutable boost::mutex  mtxCount;
    //mutable boost::mutex  mtxOStream;

    mutable Console  mConsole;
};




const boost::posix_time::seconds  Printer::DELTA =
    boost::posix_time::seconds( 1 );
