#include "../../../../include/stdafx.h"
#include "../../../../include/ge/human/event/human-live-city-event.h"
#include "../../../../include/ge/human/event/talk-human-event.h"
#include "../../../../include/ge/human/event/wait-human-event.h"
#include "../../../../include/ge/city/City.h"
#include "../../../../include/ge/human/Human.h"


void HumanLiveCity::operator()() {

    // организуем ниже по€вление разных событий
    for ( ; ; ) {

        // создаЄм другие событи€

        // идЄт на работу
        const auto ct = ManagerEvent::time();
        const bool alreadyGoWork = false;
        if ( alreadyGoWork ) {
            element()->addEvent< HumanGoWork >();
            return;
        }


        // #! ƒолжен быть boost::sleep(), если хотим корректно
        //    отработать interrupt() при завершении потока-родител€
        boost::this_thread::sleep( boost::posix_time::seconds( 1 ) );

    } // for ( ; ; )

    // ничего после не делаем
}




void HumanGoWork::operator()() {

    for ( ; ; ) {

        // человек работает заданное врем€
        // ...


        // #! ƒолжен быть boost::sleep(), если хотим корректно
        //    отработать interrupt() при завершении потока-родител€
        boost::this_thread::sleep( boost::posix_time::seconds( 1 ) );

    } // for ( ; ; )

    // #  аждое событие отвечает за целостность цепочки.
    element()->addEvent< HumanLiveCity >();
}
