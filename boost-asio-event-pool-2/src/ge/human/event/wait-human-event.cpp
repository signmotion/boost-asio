#include "../../../../include/stdafx.h"
#include "../../../../include/ge/human/event/human-live-city-event.h"
#include "../../../../include/ge/human/Human.h"


void HumanWait::operator()() {

    for ( ; ; ) {
        // @todo ����� ����� ������������ ��������� ��. �������.

        // ����. �������� ������ �������
        //const auto p = ManagerEvent::random();
        //console() << "<" << p << "> ";

        // #! ������ ���� boost::sleep(), ���� ����� ���������
        //    ���������� interrupt() ��� ���������� ������-��������
        boost::this_thread::sleep( boost::posix_time::seconds( 1 ) );
    
    } // for ( ; ; )

    // ������ ����� �� ������
}
