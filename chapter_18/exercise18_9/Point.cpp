#include "Point.h"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double xValue, double yValue)
{
    x = xValue;
    y = yValue;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}
