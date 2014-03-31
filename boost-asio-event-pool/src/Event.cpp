#include "../include/stdafx.h"
#include "../include/Event.h"


template< class T >
Event< T >::Event( std::shared_ptr< T >  element ) :
    mElement( element )
{
    assert( element );
}




template< class T >
Event< T >::~Event() {
}
