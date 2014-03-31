#pragma once

#include "../../Event.h"


/**
* События элемента 'Human'.
*/
class Human;



/**
* Элемент говорит.
*/
template< class A >
class Talk :
    public Event< A >
{
public:
    Talk();

    ~Talk();
};




/**
* Человек может перемещаться по городу.
*//*
template< class A, class B >
class Move {
    Move();

    ~Move();
};
*/
