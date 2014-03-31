#include "Printer.h"


/**
* Использование функции-члена в качестве обработчика.
*
* @source http://bravit.rsu.ru/distrib/Asio_tutorial_russian/tutorial/tuttimer4.html
*/
int main() {

    setlocale( LC_ALL, "Russian" );
    setlocale( LC_NUMERIC, "C" );



    {
        boost::asio::io_service  io;
        Printer  p( io );
        io.run();
    }



    std::cout << "\n^\n";
    std::cin.ignore();

    return 0;
}
