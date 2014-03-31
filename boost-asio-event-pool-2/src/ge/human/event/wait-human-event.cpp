#include "../../../../include/stdafx.h"
#include "../../../../include/ge/human/event/human-live-city-event.h"
#include "../../../../include/ge/human/Human.h"


void HumanWait::operator()() {

    for ( ; ; ) {
        // @todo ћожно здесь организовать по€вление др. событий.

        // случ. вызываем другие событи€
        //const auto p = ManagerEvent::random();
        //console() << "<" << p << "> ";

        // #! ƒолжен быть boost::sleep(), если хотим корректно
        //    отработать interrupt() при завершении потока-родител€
        boost::this_thread::sleep( boost::posix_time::seconds( 1 ) );
    
    } // for ( ; ; )

    // ничего после не делаем
}
