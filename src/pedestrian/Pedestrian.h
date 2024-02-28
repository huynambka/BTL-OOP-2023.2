#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include <vector>
#include "src/ward/Ward.h"
#include "src/point/Point.h"
#include "src/emotion/Emotion.h"
#include "src/personality/Personality.h"
#include "src/event/Event.h"
#include "src/agv-event/AGVEvent.h"
#include "lib/nlohmann/json.hpp"

using json = nlohmann::json;

enum WalkAbility
{
    noDisability,
    crutches,
    sticks,
    wheelchairs,
    blind
};

class Pedestrian
{
protected:
    int id;
    Ward start;
    Ward end;
    std::vector<Ward> journey;
    double velocity;
    Personality personality;
    Emotion emotion;
    std::vector<Event> events;
    double walkingTime;
    double distance;
    double age;
    AGVEvent impactOfAGV;
    std::vector<Point> tempPoints;

public:
    Pedestrian();
    ~Pedestrian();

    int getId() const { return id; }

    json toJson();
};

#endif