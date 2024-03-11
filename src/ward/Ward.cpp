#include "Ward.h"

json Ward::toJson()
{
    json jsonObj; // TODO: Implement this function
    jsonObj["name"] = this->name;
    jsonObj["entrance"] = this->entrance.toJson();
    jsonObj["exit"] = this->exit.toJson();
    jsonObj["wall"] = json::array();
    for (auto &point : this->wall)
    {
        jsonObj["wall"].push_back(point.toJson());
    }
    return jsonObj;
}