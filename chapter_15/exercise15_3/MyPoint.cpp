#include "MyPoint.h"
#include <cmath>

MyPoint::MyPoint()
{
    x = 0;
    y = 0;
}

MyPoint::MyPoint(double x, double y)
{
    this->x = x;
    this->y = y;
}

double MyPoint::getX() const
{
    return x;
}

double MyPoint::getY() const
{
    return y;
}

double MyPoint::distance(const MyPoint &endPoint) const
{
    return std::sqrt((endPoint.getX() - x) * (endPoint.getX() - x) +
                     (endPoint.getY() - y) * (endPoint.getY() - y));
}
