#include "Event.h"

Event::Event() {}

json Event::toJson()
{
    json jsonObj;
    jsonObj["intensity"] = this->intensity;
    jsonObj["time"] = this->time;
    return jsonObj;
}