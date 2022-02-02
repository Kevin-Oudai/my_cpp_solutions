// Listing 9.10 - CircleWithPrivateDataFields.cpp

#include "CircleWithPrivateDataFields.h"

// Construct a default circle object
Circle::Circle()
{
    radius = 1;
}

// Construct a circle object
Circle::Circle(double newRadius)
{
    radius = newRadius;
}

// Return the area of this circle
double Circle::getArea()
{
    return radius * radius * 3.14159;
}

// Return the radius of this circle
double Circle::getRadius()
{
    return radius;
}

// Set a new radius
void Circle::setRadius(double newRadius)
{
    radius = (newRadius >= 0) ? newRadius : 0;
}