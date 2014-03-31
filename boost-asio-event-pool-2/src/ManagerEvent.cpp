#include "../include/stdafx.h"
#include "../include/ManagerEvent.h"
#include "../include/Event.h"


ManagerEvent::ManagerEvent() :
    mPool( 4 )
{
}




ManagerEvent::~ManagerEvent() {
    mPool.interruptAll();
}




void ManagerEvent::push( std::shared_ptr< Event >  e ) {
    // добавим событие в пул
    mPool.enqueue< void >( [ e ] () {
        // # —обытие само позаботитс€ о целостности цепочки.
        ( *e )();
    } );

    {
        Console::instance() << "ƒобавлено " << e << " " <<
            typeid( *e ).name() <<
            " дл€ " << typeid( *e->element() ).name() << "." << std::endl;
    }
}




size_t ManagerEvent::time() {
    using namespace boost::gregorian;
    using namespace boost::local_time;
    using namespace boost::posix_time;

    static boost::mutex  mtxThis;
    boost::mutex::scoped_lock  lock( mtxThis );

    static const ptime  epoch( date( 1970, 1, 1 ) );
    const ptime  now = microsec_clock::local_time();
    const time_duration  diff = now - epoch;

    return diff.total_seconds();
}




size_t ManagerEvent::random() {
    static boost::mutex  mtxThis;
    boost::mutex::scoped_lock  lock( mtxThis );

    static boost::mt19937  gen( 12345 );
    static boost::uniform_int<>  uni( 0, INT_MAX );
    static boost::variate_generator< boost::mt19937&, boost::uniform_int<> >
        rg( gen, uni );

    return rg();
}
