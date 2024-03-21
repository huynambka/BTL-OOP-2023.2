#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include <iostream>
#include <vector>
// #include "src/ward/Ward.h"
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

struct Ward
{
    std::string name;
    Point entrance;
    Point exit;
    std::vector<Point> wall;
    void setName(std::string name) { this->name = name; }
    void setEntrance(Point entrance) { this->entrance = entrance; }
    void setExit(Point exit) { this->exit = exit; }
    json toJson()
    {
        json jsonObj;
        jsonObj["name"] = this->name;
        jsonObj["entrance"] = this->entrance.toJson();
        jsonObj["exit"] = this->exit.toJson();
        jsonObj["wall"] = json::array();
        for (auto &point : this->wall)
        {
            jsonObj["wall"].push_back(point.toJson());
        }
        return jsonObj;
    }
};

class Pedestrian
{

protected:
    int id;
    Ward start;
    Ward end;
    WalkAbility walkAbility;
    std::vector<Ward> journey;
    double velocity;
    Personality personality;
    Emotion emotion;
    std::vector<Event *> events;
    std::vector<float> eventTimeDistances;
    // double walkingTime;
    // double distance;
    double age;
    AGVEvent impactOfAGV;
    std::vector<Point> tempPoints;

public:
    static int idCounter;
    Pedestrian();
    ~Pedestrian();
    void setAge(float age) { this->age = age; }
    void setVelocity(double velocity) { this->velocity = velocity; }
    int getId() const { return id; }
    void setWalkAbility(WalkAbility walkAbility) { this->walkAbility = walkAbility; }
    void setPersonality(Personality personality) { this->personality = personality; }
    void setEvents(std::vector<Event *> events) { this->events = events; }
    void setEventTimeDistances(std::vector<float> eventTimeDistances) { this->eventTimeDistances = eventTimeDistances; }
    json toJson();
};

#endif