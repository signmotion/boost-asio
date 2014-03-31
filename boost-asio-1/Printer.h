#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


class Printer {
public:
    inline Printer(
        boost::asio::io_service& io
    ) :
        mTimer( io, DELTA ),
        mCount( 0 )
    {
        mTimer.async_wait( boost::bind( &Printer::print, this ) );
    }




    inline ~Printer() {
        std::cout << "Final count is " << mCount << "\n";
    }




    inline void print() {
        if (mCount < 5) {
            std::cout << mCount << "\n";
            ++mCount;

            mTimer.expires_at( mTimer.expires_at() + DELTA );
            mTimer.async_wait( boost::bind( &Printer::print, this ) );
        }
    }




private:
    boost::asio::deadline_timer  mTimer;
    int  mCount;

    static const boost::posix_time::seconds  DELTA;
};




const boost::posix_time::seconds  Printer::DELTA =
    boost::posix_time::seconds( 1 );
