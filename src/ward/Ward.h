#ifndef WARDS_H
#define WARDS_H

#include <vector>
#include "../point/Point.h"

class Ward
{
protected:
    Point entrance;
    Point exit;
    std::vector<Point> wall;
};

#endif