#include "Personality.h"
#include <cmath>
Personality::Personality()
{
}

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
    jsonObj["positiveEmotionThreshold"] = round(this->positiveEmotionThreshold * 10) / 10;
    jsonObj["negativeEmotionThreshold"] = round(this->negativeEmotionThreshold * 10) / 10;
    return jsonObj;
}