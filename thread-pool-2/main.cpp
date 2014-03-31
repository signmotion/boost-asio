#include <iostream>
#include "PoolThread.h"


/**
* ��� �������.
*
* @project https://github.com/progschj/ThreadPool
*/
int main() {

    setlocale( LC_ALL, "Russian" );
    setlocale( LC_NUMERIC, "C" );



    {
        // �������� ��� �� 4 ���������� ����������� �������
        PoolThread  pool( 4 );
 
        // �������� ������� ��������� ���� �� ����������
        std::vector< Result< int > >  result;
        for (size_t i = 0; i < 8; ++i) {
            result.push_back( pool.enqueue< int >(
                [ i ] () -> int {
                    // ������� ������� � ������� ����
                    std::cout << "hello " << i << std::endl;
                    boost::this_thread::sleep(
                        boost::posix_time::milliseconds( 1000 )
                    );
                    std::cout << "world " << i << std::endl;

                    return i * i;
            } ) );
        }

        std::cout << "\n\nAll result:\n";
        for (size_t i = 0; i < 8; ++i) {
            std::cout << "\"" << result[ i ].get() << "\" \n";
        }
    }



    std::cout << "\n^\n";
    std::cin.ignore();

    return 0;
}
