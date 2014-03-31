#pragma once

#include <ostream>
#include <boost/thread/recursive_mutex.hpp>


/**
* ѕотокобезопасна€ консоль.
*
* @example
*   mConsole << "Any info" << ...;
*/
class Console {
public:
    inline Console( std::ostream* out = nullptr ) : mOut( out ) {
    }

    virtual inline ~Console() {
        // блокировки снимутс€ при уничтожении всех объектов этого класса
    }

    inline std::ostream& out() {
        return (mOut ? *mOut : std::cout);
    }


    template< class T >
    inline Console& operator<<( const T& data ) {
        boost::recursive_mutex::scoped_lock  lock( mtx );
        out() << data;
        return *this;
    }

    // дл€ манипул€торов
    inline Console& operator<<( std::ostream& ( *pf )( std::ostream& ) ) {
        boost::recursive_mutex::scoped_lock  lock( mtx );
        out() << pf;
        return *this;
    }


private:
    std::ostream*  mOut;

    static boost::recursive_mutex  mtx;
};
