#include "include/stdafx.h"
#include "include/ge/city/City.h"
#include "include/ge/human/Human.h"


/**
* Пул событий.
* События могут выстраиваться в цепочки.
*
* @see boost-asio-thread-pool
*/
int main() {

    setlocale( LC_ALL, "Russian" );
    setlocale( LC_NUMERIC, "C" );



    {
        // воплотим человека
        auto boris = std::make_shared< Human >( "Boris" );

        // создадим город
        auto montevey = std::make_shared< City >( "Montevey" );

        // попросим человека что-то сказать
        {
            protocolDataEvent_t  data;
            data[ "phrase" ] = "Hi!";
            boris->addEvent< HumanTalk >( data );
        }

        // поселим человека в городе
        {
            // технически: назначим ему событие "Жить в городе"
            montevey->addEvent< HumanLiveCity >();
        }


        // ждём Enter
        std::cout << "\nМир создан.\n" << std::endl;
        std::cin.ignore();
    }



    std::cout << "\n^\n";
    std::cin.ignore();

    return 0;
}
