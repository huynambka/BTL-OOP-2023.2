#ifndef EVENT_H
#define EVENT_H

#include "lib/nlohmann/json.hpp"
using json = nlohmann::json;
class Event
{
protected:
    double intensity;
    int time;

public:
    Event();
    json toJson();
};

#endif