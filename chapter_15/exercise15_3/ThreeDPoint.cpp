#include "ThreeDPoint.h"
#include <cmath>

ThreeDPoint::ThreeDPoint() : MyPoint(0, 0)
{
    z = 0;
}

ThreeDPoint::ThreeDPoint(double x, double y, double z) : MyPoint(x, y)
{
    this->z = z;
}

double ThreeDPoint::getZ() const
{
    return z;
}

double ThreeDPoint::distance(const ThreeDPoint &endPoint) const
{
    return std::sqrt((endPoint.getX() - getX()) * (endPoint.getX() - getX()) +
                     (endPoint.getY() - getY()) * (endPoint.getY() - getY()) +
                     (endPoint.getZ() - z) * (endPoint.getZ() - z));
}
