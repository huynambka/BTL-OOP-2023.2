#ifndef VISITOR_H
#define VISITOR_H

#include "src/pedestrian/Pedestrian.h"
#include "lib/nlohmann/json.hpp"

using json = nlohmann::json;

class Visitor : public Pedestrian
{
protected:
    WalkAbility walkAbility;

public:
    json toJson();
};

#endif