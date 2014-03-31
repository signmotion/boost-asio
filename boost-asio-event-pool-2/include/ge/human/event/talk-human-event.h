#pragma once

#include "../../../Event.h"


/**
* Человек говорит.
*/
class HumanTalk :
    public Event
{
public:
    inline HumanTalk(
        std::shared_ptr< GE >  e,
        const protocolDataEvent_t&  data
    ) :
        Event( e, data ) {
    }

    inline ~HumanTalk() {
    }

    virtual void operator()();
};
