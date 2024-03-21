#include "Event.h"

Event::Event() {}

json Event::toJson()
{
    json jsonObj;
    jsonObj["intensity"] = round(this->intensity * 100) / 100;
    jsonObj["time"] = this->time;
    return jsonObj;
}