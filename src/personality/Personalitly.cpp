#include "Personality.h"

Personality::Personality(double lamda, double ne, double pos)
{
    this->lamda = lamda;
    this->positiveEmotionThreshold = pos;
    this->negativeEmotionThreshold = ne;
}
Personality::~Personality() {}

json Personality::toJson()
{
    json jsonObj;
    jsonObj["lamda"] = this->lamda;
    jsonObj["positiveEmotionThreshold"] = this->positiveEmotionThreshold;
    jsonObj["negativeEmotionThreshold"] = this->negativeEmotionThreshold;
    return jsonObj;
}