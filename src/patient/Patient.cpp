#include "Patient.h"

json Patient::toJson()
{
    json jsonObj = Pedestrian::toJson();
    jsonObj["walkAbility"] = this->walkAbility;
    return jsonObj;
}