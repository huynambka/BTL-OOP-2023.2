#include "Pedestrian.h"

Pedestrian::Pedestrian()
{
    this->id = idCounter++;
}

Pedestrian::~Pedestrian()
{
}

json Pedestrian::toJson()
{
    json jsonObj;
    jsonObj["id"] = this->id;
    jsonObj["start"] = this->start.toJson();
    jsonObj["end"] = this->end.toJson();
    jsonObj["journey"] = json::array();
    for (auto &ward : this->journey)
    {
        jsonObj["journey"].push_back(ward.toJson());
    }
    jsonObj["velocity"] = this->velocity;
    jsonObj["personality"] = this->personality.toJson();
    jsonObj["emotion"] = this->emotion.toJson();
    jsonObj["events"] = json::array();
    for (auto &event : this->events)
    {
        jsonObj["events"].push_back(event.toJson());
    }
    jsonObj["walkingTime"] = this->walkingTime;
    jsonObj["distance"] = this->distance;
    jsonObj["age"] = this->age;
    jsonObj["impactOfAGV"] = this->impactOfAGV.toJson();
    jsonObj["tempPoints"] = json::array();
    for (auto &point : this->tempPoints)
    {
        jsonObj["tempPoints"].push_back(point.toJson());
    }
}