#ifndef PATIENT_H
#define PATIENT_H

#include "../pedestrian/Pedestrian.h"

enum WalkAbility
{
    noDisability,
    crutches,
    sticks,
    wheelchairs,
    blind
};

class Patient : public Pedestrian
{
protected:
    WalkAbility walkAbility;
};

#endif