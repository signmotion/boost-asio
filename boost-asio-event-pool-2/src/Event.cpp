#include "../include/stdafx.h"
#include "../include/Event.h"


Event::Event(
    std::shared_ptr< GE >          element,
    const typelib::json::Variant&  data
) :
    mElement( element ),
    mData( data )
{
    assert( element );
}




Event::~Event() {
}
