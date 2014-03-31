#pragma once

#include "../../../Event.h"


/**
* Человек ждёт.
*/
class HumanWait :
    public Event
{
public:
    inline HumanWait(
        std::shared_ptr< GE >  e,
        const protocolDataEvent_t&  data
    ) :
        Event( e, data ) {
    }

    inline ~HumanWait() {
    }

    virtual void operator()();
};
