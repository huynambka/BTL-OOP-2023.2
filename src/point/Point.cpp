#include "Point.h"
#include <cmath>
Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}

void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }

nlohmann::json Point::toJson()
{
    nlohmann::json jsonObj;
    jsonObj["x"] = round(this->x * 100) / 100;
    jsonObj["y"] = round(this->y * 100) / 100;
    return jsonObj;
}