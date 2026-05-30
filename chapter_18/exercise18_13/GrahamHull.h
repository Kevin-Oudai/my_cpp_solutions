#ifndef GRAHAMHULL_H
#define GRAHAMHULL_H

#include <vector>
#include "MyPoint.h"

class GrahamHull
{
public:
    std::vector<MyPoint> getConvexHull(std::vector<MyPoint>& s) const;

private:
    double crossProduct(const MyPoint& p0, const MyPoint& p1, const MyPoint& p2) const;
    double distanceSquared(const MyPoint& p1, const MyPoint& p2) const;
    int getLowestPointIndex(std::vector<MyPoint>& points) const;
    void sortByAngle(std::vector<MyPoint>& points, const MyPoint& start) const;
};

#endif
