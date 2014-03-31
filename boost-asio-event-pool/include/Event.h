#pragma once


/**
* Событие элемента.
*/
template< class T >
class Event {
public:
    Event( std::shared_ptr< T > );

    virtual ~Event();


private:
    std::weak_ptr< T >  mElement;
};
