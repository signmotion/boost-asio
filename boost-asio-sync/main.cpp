#include "Printer.h"


/**
* Запуск в нескольких потоках. Общие ресурсы. Синхронизация.
*
* @source http://bravit.rsu.ru/distrib/Asio_tutorial_russian/tutorial/tuttimer5.html
*/
int main() {

    setlocale( LC_ALL, "Russian" );
    setlocale( LC_NUMERIC, "C" );



    {
        boost::asio::io_service  io;
        Printer  p( io );
        boost::thread  th( boost::bind( &boost::asio::io_service::run, &io ) );
        io.run();
        th.join();
    }



    std::cout << "\n^\n";
    std::cin.ignore();

    return 0;
}
