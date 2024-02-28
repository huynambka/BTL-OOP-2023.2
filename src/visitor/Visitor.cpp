#include "Visitor.h"

json Visitor::toJson()
{
    json jsonObj = Pedestrian::toJson();
    jsonObj["walkAbility"] = this->walkAbility;
    return jsonObj;
}