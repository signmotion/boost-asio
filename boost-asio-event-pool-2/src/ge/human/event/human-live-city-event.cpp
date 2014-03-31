#include "../../../../include/stdafx.h"
#include "../../../../include/ge/human/event/human-live-city-event.h"
#include "../../../../include/ge/human/event/talk-human-event.h"
#include "../../../../include/ge/human/event/wait-human-event.h"
#include "../../../../include/ge/city/City.h"
#include "../../../../include/ge/human/Human.h"


void HumanLiveCity::operator()() {

    // ���������� ���� ��������� ������ �������
    for ( ; ; ) {

        // ������ ������ �������

        // ��� �� ������
        const auto ct = ManagerEvent::time();
        const bool alreadyGoWork = false;
        if ( alreadyGoWork ) {
            element()->addEvent< HumanGoWork >();
            return;
        }


        // #! ������ ���� boost::sleep(), ���� ����� ���������
        //    ���������� interrupt() ��� ���������� ������-��������
        boost::this_thread::sleep( boost::posix_time::seconds( 1 ) );

    } // for ( ; ; )

    // ������ ����� �� ������
}




void HumanGoWork::operator()() {

    for ( ; ; ) {

        // ������� �������� �������� �����
        // ...


        // #! ������ ���� boost::sleep(), ���� ����� ���������
        //    ���������� interrupt() ��� ���������� ������-��������
        boost::this_thread::sleep( boost::posix_time::seconds( 1 ) );

    } // for ( ; ; )

    // # ������ ������� �������� �� ����������� �������.
    element()->addEvent< HumanLiveCity >();
}
