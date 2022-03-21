#include "CircleWithDestructor.h"

int Circle::numberOfObjects = 0;

// Construce a default circle object
Circle::Circle()
{
    radius = 1;
    numberOfObjects++;
}

// Construct a circle object
Circle::Circle(double radius)
{
    this->radius = radius;
    numberOfObjects++;
}

// Return the area of the circle
double Circle::getArea() const
{
    return radius * radius * 3.14159;
}

// Return the radius of this circle
double Circle::getRadius() const
{
    return radius;
}

// Set a new radius
void Circle::setRadius(double radius)
{
    this->radius = (radius >= 0) ? radius : 0;
}

// Return the number of circle objects
int Circle::getNumberOfObjects()
{
    return numberOfObjects;
}

// Destruct a circle object
Circle::~Circle()
{
    numberOfObjects--;
}