// Listing 10.7 - CircleWithStaticDataFields.cpp

#include "CircleWithStaticDataFields.h"

int Circle::numberOfObjects = 0;

// Construct a circle object
Circle::Circle()
{
    radius = 1;
    numberOfObjects++;
}

// Construct a circle object
Circle::Circle(double newRadius)
{
    radius = newRadius;
    numberOfObjects++;
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

// Return the number of circle objects
int Circle::getNumberOfObjects()
{
    return numberOfObjects;
}