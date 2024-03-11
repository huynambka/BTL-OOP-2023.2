#include "Personnel.h"

Personnel::Personnel()
{
    this->walkAbility = noDisability;
}
json Personnel::toJson()
{
    json jsonObj = Pedestrian::toJson();
    return jsonObj;
}