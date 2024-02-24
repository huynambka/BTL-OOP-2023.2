#ifndef POINT_H
#define POINT_H

class Point
{
protected:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX() const { return x; }
    double getY() const { return y; }
    Point getPoint() const { return *this; }
};

#endif