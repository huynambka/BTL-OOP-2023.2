#include "Personality.h"

Personality::Personality() {}
Personality::~Personality() {}

json Personality::toJson()
{
    json jsonObj;
    jsonObj["lamda"] = this->lamda;
    jsonObj["positiveEmotionThreshold"] = this->positiveEmotionThreshold;
    jsonObj["negativeEmotionThreshold"] = this->negativeEmotionThreshold;
    return jsonObj;
}