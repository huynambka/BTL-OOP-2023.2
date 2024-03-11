#ifndef PATIENT_H
#define PATIENT_H

#include "src/pedestrian/Pedestrian.h"
#include "lib/nlohmann/json.hpp"

using json = nlohmann::json;
class Patient : public Pedestrian
{
protected:
public:
    json toJson();
};

#endif