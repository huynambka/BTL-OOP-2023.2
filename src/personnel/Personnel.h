#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "src/pedestrian/Pedestrian.h"
#include "lib/nlohmann/json.hpp"

using json = nlohmann::json;
class Personnel : public Pedestrian
{
protected:
public:
    Personnel();
    json toJson();
};

#endif