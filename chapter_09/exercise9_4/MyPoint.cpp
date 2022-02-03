#include <cmath>
#include "MyPoint.h"

MyPoint::MyPoint()
{
    x = 0;
    y = 0;
}

MyPoint::MyPoint(double a, double b)
{
    x = a;
    y = b;
}

double MyPoint::getX()
{
    return x;
}

double MyPoint::getY()
{
    return y;
}

double MyPoint::distance(MyPoint endPoint)
{
    double dist = std::sqrt(
        std::pow(endPoint.getX() - x, 2) +
        std::pow(endPoint.getY() - y, 2));
    return dist;
}