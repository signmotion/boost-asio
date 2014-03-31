#pragma once

#include "../GE.h"
#include "../StoreEvent.h"
#include "../ge/Human.h"
#include "../ge/event/human-event.h"


class Human :
    public GE,
    public StoreEvent< Talk< Human > >
{
public:
    Human( const std::string& name );

    virtual ~Human();


    template< class E >
    void desire( const std::string& phrase );


private:
    const std::string  mName;
};
