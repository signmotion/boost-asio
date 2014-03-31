#include "../include/stdafx.h"
#include "../include/StoreEvent.h"
#include "../include/ge/Human.h"
#include "../include/ge/event/human-event.h"


template< class T >
StoreEvent< T >::StoreEvent() {
}


template
StoreEvent< Talk< Human > >::StoreEvent();




template< class T >
StoreEvent< T >::~StoreEvent() {
}


template
StoreEvent< Talk< Human > >::~StoreEvent();
