#ifndef AGVEVENT_H
#define AGVEVENT_H

#include "../event/Event.h"

class AGVEvent : public Event
{
protected:
    double impact;
    double time;
};

#endif