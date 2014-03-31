#include <iostream>
#include "PoolThread.h"


/**
* Пул потоков.
*
* @source http://progsch.net/wordpress/?p=71
* @project https://github.com/progschj/ThreadPool
*/
int main() {

    setlocale( LC_ALL, "Russian" );
    setlocale( LC_NUMERIC, "C" );



    {
        // создадим пул из 4 асинхронно исполняемых потоков
        PoolThread< 4 >  pool;
 
        // отправим очередь элементов пулу на исполнение
        for (size_t i = 0; i < 8; ++i) {
            pool.enqueue(
            [ i ] {
                // ожидаем увидеть в консоли хаос
                std::cout << "hello " << i << std::endl;
                boost::this_thread::sleep(
                    boost::posix_time::milliseconds( 1000 )
                );
                std::cout << "world " << i << std::endl;
            } );
        }
    }



    std::cout << "\n^\n";
    std::cin.ignore();

    return 0;
}
