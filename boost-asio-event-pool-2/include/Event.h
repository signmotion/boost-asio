#pragma once

#include "GE.h"


/**
* Событие элемента.
*/
class Event {
public:
    Event( std::shared_ptr< GE >,  const protocolDataEvent_t& );

    virtual ~Event();

    virtual void operator()() = 0;


    inline const std::shared_ptr< GE >  element() const {
        assert( !mElement.expired()
            && "Элемент уничтожен." );
        return mElement.lock();
    }


    template< typename T >
    inline T data( const std::string& name, const T& def = T() ) const {
        return mData.at< T >( name, def );
    };


protected:
    std::weak_ptr< GE >  mElement;

    /**
    * Конфигурация события.
    */
    const protocolDataEvent_t  mData;
};
