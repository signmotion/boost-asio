#pragma once

#include "GE.h"


/**
* ������� ��������.
*/
class Event {
public:
    Event( std::shared_ptr< GE >,  const protocolDataEvent_t& );

    virtual ~Event();

    virtual void operator()() = 0;


    inline const std::shared_ptr< GE >  element() const {
        assert( !mElement.expired()
            && "������� ���������." );
        return mElement.lock();
    }


    template< typename T >
    inline T data( const std::string& name, const T& def = T() ) const {
        return mData.at< T >( name, def );
    };


protected:
    std::weak_ptr< GE >  mElement;

    /**
    * ������������ �������.
    */
    const protocolDataEvent_t  mData;
};
