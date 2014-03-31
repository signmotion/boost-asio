#pragma once

#include "PoolThread.h"


class Event;


class ManagerEvent {
public:
    ManagerEvent();

    virtual ~ManagerEvent();


    void push( std::shared_ptr< Event > );


    /**
    * @return “екущее врем€, доступное из разных потоков, с.
    */
    static size_t time();


    /**
    * @return —лучайные числа, доступные из разных потоков.
    */
    static size_t random();


private:
    PoolThread  mPool;
};
