#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include <vector>
#include "../ward/Ward.h"
#include "../point/Point.h"
#include "../emotion/Emotion.h"
#include "../personality/Personality.h"
#include "../event/Event.h"
#include "../agv-event/AGVEvent.h"

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
};

#endif