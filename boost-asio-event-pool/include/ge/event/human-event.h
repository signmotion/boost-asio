#pragma once

#include "../../Event.h"


/**
* ������� �������� 'Human'.
*/
class Human;



/**
* ������� �������.
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
* ������� ����� ������������ �� ������.
*//*
template< class A, class B >
class Move {
    Move();

    ~Move();
};
*/
