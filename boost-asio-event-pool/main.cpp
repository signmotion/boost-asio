#include "include/stdafx.h"
#include "include/PoolThread.h"
#include "include/ge/Human.h"
#include "include/ge/event/human-event.h"

- Плохая структура. Из-за шаблонов поддержка большого проекта выливается
  в сложный ребус. См. др. версию.


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

        // попросим его сказать "Привет!"
        boris->desire< Talk< Human > >( "Hi!" );

    }



    std::cout << "\n^\n";
    std::cin.ignore();

    return 0;
}
