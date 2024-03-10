#ifndef EMOTION_H
#define EMOTION_H

#include "lib/nlohmann/json.hpp"
using json = nlohmann::json;
class Emotion
{
protected:
    double pleasure;
    double surprise;
    double anger;
    double fear;
    double hate;
    double sad;

public:
    Emotion();
    json toJson();
};

#endif