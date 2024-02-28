#include "Personnel.h"

json Personnel::toJson()
{
    json jsonObj = Pedestrian::toJson();
    return jsonObj;
}