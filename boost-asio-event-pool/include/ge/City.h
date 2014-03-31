#pragma once

#include "../GE.h"
#include "../StoreEvent.h"


class City :
    public GE,
    public StoreEvent< City >
{
public:
    City();

    virtual ~City();
};
