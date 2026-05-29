#ifndef THREEDPOINT_H
#define THREEDPOINT_H

#include "MyPoint.h"

class ThreeDPoint : public MyPoint
{
public:
    ThreeDPoint();
    ThreeDPoint(double x, double y, double z);

    double getZ() const;
    double distance(const ThreeDPoint &endPoint) const;

private:
    double z;
};

#endif
