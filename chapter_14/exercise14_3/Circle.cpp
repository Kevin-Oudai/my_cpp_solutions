#include "Circle.h"

Circle::Circle()
{
    radius = 1;
}

Circle::Circle(double newRadius)
{
    radius = newRadius;
}

double Circle::getArea() const
{
    return radius * radius * 3.14159;
}

double Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(double newRadius)
{
    radius = newRadius;
}

bool Circle::operator<(const Circle &secondCircle) const
{
    return radius < secondCircle.radius;
}

bool Circle::operator<=(const Circle &secondCircle) const
{
    return radius <= secondCircle.radius;
}

bool Circle::operator==(const Circle &secondCircle) const
{
    return radius == secondCircle.radius;
}

bool Circle::operator!=(const Circle &secondCircle) const
{
    return radius != secondCircle.radius;
}

bool Circle::operator>(const Circle &secondCircle) const
{
    return radius > secondCircle.radius;
}

bool Circle::operator>=(const Circle &secondCircle) const
{
    return radius >= secondCircle.radius;
}
