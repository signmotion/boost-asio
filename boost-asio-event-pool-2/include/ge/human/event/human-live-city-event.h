#pragma once

#include "../../../Event.h"


/**
* ������� ���� � ������.
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
* ������� ��� �� ������.
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
