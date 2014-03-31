#pragma once

#include "PoolThread.h"


class Event;


class ManagerEvent {
public:
    ManagerEvent();

    virtual ~ManagerEvent();


    void push( std::shared_ptr< Event > );


    /**
    * @return ������� �����, ��������� �� ������ �������, �.
    */
    static size_t time();


    /**
    * @return ��������� �����, ��������� �� ������ �������.
    */
    static size_t random();


private:
    PoolThread  mPool;
};
