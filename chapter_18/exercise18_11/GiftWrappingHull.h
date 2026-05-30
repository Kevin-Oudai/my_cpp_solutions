#ifndef GIFTWRAPPINGHULL_H
#define GIFTWRAPPINGHULL_H

#include <vector>
#include "MyPoint.h"

class GiftWrappingHull
{
public:
    std::vector<MyPoint> getConvexHull(std::vector<MyPoint>& s) const;

private:
    double crossProduct(const MyPoint& p0, const MyPoint& p1, const MyPoint& p2) const;
    double distanceSquared(const MyPoint& p1, const MyPoint& p2) const;
};

#endif
