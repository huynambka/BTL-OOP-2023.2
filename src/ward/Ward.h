#ifndef WARDS_H
#define WARDS_H

#include <vector>
#include "src/point/Point.h"
#include "lib/nlohmann/json.hpp"

using json = nlohmann::json;
class Ward
{
protected:
    Point entrance;
    Point exit;
    std::vector<Point> wall;

public:
    json toJson();
};

#endif