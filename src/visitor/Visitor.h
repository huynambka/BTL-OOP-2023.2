#ifndef VISITOR_H
#define VISITOR_H

enum WalkAbility
{
    noDisability,
    crutches,
    sticks,
    wheelchairs,
    blind
};
class Visitor
{
protected:
    WalkAbility walkAbility;

public:
};

#endif