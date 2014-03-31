#include "include/stdafx.h"
#include "include/ge/city/City.h"
#include "include/ge/human/Human.h"


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

        // �������� �����
        auto montevey = std::make_shared< City >( "Montevey" );

        // �������� �������� ���-�� �������
        {
            protocolDataEvent_t  data;
            data[ "phrase" ] = "Hi!";
            boris->addEvent< HumanTalk >( data );
        }

        // ������� �������� � ������
        {
            // ����������: �������� ��� ������� "���� � ������"
            montevey->addEvent< HumanLiveCity >();
        }


        // ��� Enter
        std::cout << "\n��� ������.\n" << std::endl;
        std::cin.ignore();
    }



    std::cout << "\n^\n";
    std::cin.ignore();

    return 0;
}
