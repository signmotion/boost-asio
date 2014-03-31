#include "include/stdafx.h"
#include "include/PoolThread.h"
#include "include/ge/Human.h"
#include "include/ge/event/human-event.h"

- ������ ���������. ��-�� �������� ��������� �������� ������� ����������
  � ������� �����. ��. ��. ������.


/**
* ��� �������.
* ������� ����� ������������� � �������.
*
* @see boost-asio-thread-pool
*/
int main() {

    setlocale( LC_ALL, "Russian" );
    setlocale( LC_NUMERIC, "C" );



    {
        // �������� ��������
        auto boris = std::make_shared< Human >( "Boris" );

        // �������� ��� ������� "������!"
        boris->desire< Talk< Human > >( "Hi!" );

    }



    std::cout << "\n^\n";
    std::cin.ignore();

    return 0;
}
