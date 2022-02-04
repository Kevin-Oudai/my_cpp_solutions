#include <iostream>
#include "Fan.h"

Fan::Fan()
{
    speed = 1;
    on = false;
    radius = 5;
}

int Fan::getSpeed()
{
    return speed;
}

bool Fan::getState()
{
    return on;
}

double Fan::getRadius()
{
    return radius;
}

void Fan::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

void Fan::setState(bool state)
{
    on = state;
}

void Fan::setRadius(double newRadius)
{
    radius = newRadius;
}