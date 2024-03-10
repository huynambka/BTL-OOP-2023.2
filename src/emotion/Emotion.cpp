#include "Emotion.h"

Emotion::Emotion() : pleasure(0.75), surprise(0.5), anger(-0.2), fear(-0.2), hate(-0.4), sad(-0.4) {}

json Emotion::toJson()
{
    json jsonObj;
    jsonObj["pleasure"] = pleasure;
    jsonObj["surprise"] = surprise;
    jsonObj["anger"] = anger;
    jsonObj["fear"] = fear;
    jsonObj["hate"] = hate;
    jsonObj["sad"] = sad;
    return jsonObj;
}