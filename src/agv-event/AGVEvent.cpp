#include "AGVEvent.h"

AGVEvent::AGVEvent() {}
AGVEvent::~AGVEvent() {}
json AGVEvent::toJson()
{
    json jsonObj;
    jsonObj["impact"] = round(this->impact * 100) / 100;
    jsonObj["time"] = this->time;
    return jsonObj;
}