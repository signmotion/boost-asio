#pragma once

#include "../../GE.h"
#include "event/human-live-city-event.h"
#include "event/talk-human-event.h"
#include "event/wait-human-event.h"


class Human :
    public GE
{
public:
    Human( const std::string& name );

    virtual ~Human();
};
