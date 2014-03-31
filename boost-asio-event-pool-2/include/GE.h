#pragma once

#include "struct.h"
#include "ManagerEvent.h"
#include "Console.h"


/**
* Ёлемент игры.
*/
class GE :
    public std::enable_shared_from_this< GE >
{
public:
    GE( const std::string& name );

    virtual ~GE();


    /**
    * —оздаЄт и добавл€ет новое событие.
    */
    template< class A >
    inline void addEvent(
        const protocolDataEvent_t& data = protocolDataEvent_t()
    ) {
        std::shared_ptr< A >  a( new A( this->shared_from_this(), data ) );
        mManagerEvent->push( a );
    }


    const std::string& name() const {
        return mName;
    }


protected:
    const std::string  mName;


private:
    static std::unique_ptr< ManagerEvent >  mManagerEvent;
};
