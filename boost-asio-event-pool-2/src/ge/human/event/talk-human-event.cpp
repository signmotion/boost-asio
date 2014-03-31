#include "../../../../include/stdafx.h"
#include "../../../../include/ge/human/event/talk-human-event.h"
#include "../../../../include/ge/human/event/wait-human-event.h"
#include "../../../../include/ge/human/Human.h"


void HumanTalk::operator()() {

    const std::string msg = data< std::string >( "phrase" );
    // �������
    Console::instance() << this << "\t" << msg << "\n";

    if (msg == "Hi!") {
        // ���� ������� "������!", ����� ������� "��� ����?"
        protocolDataEvent_t  data;
        data[ "phrase" ] = "How's tricks??";
        element()->addEvent< HumanTalk >( data );
    }

    // ����� - ���
    element()->addEvent< HumanWait >();
}
