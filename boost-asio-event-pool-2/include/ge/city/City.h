#pragma once

#include "../../GE.h"


class City :
    public GE
{
public:
    City( const std::string& name );

    virtual ~City();
};
