#pragma once

#include "../../../Event.h"


/**
* Человек живёт в городе.
*/
class HumanLiveCity :
    public Event
{
public:
    inline HumanLiveCity(
        std::shared_ptr< GE >  e,
        const protocolDataEvent_t&  data
    ) :
        Event( e, data ) {
    }

    inline ~HumanLiveCity() {
    }

    virtual void operator()();
};




/**
* Человек идёт на работу.
*/
class HumanGoWork :
    public Event
{
public:
    inline HumanGoWork(
        std::shared_ptr< GE >  e,
        const protocolDataEvent_t&  data
    ) :
        Event( e, data ) {
    }

    inline ~HumanGoWork() {
    }

    virtual void operator()();
};
