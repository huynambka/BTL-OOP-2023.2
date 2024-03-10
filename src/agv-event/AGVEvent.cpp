#include "AGVEvent.h"

AGVEvent::AGVEvent() {}
AGVEvent::~AGVEvent() {}
json AGVEvent::toJson()
{
    json jsonObj = Event::toJson();
    jsonObj["impact"] = this->impact;
    jsonObj["time"] = this->time;
    return jsonObj;
}