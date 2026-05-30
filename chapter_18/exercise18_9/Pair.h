#ifndef PAIR_H
#define PAIR_H

#include "Point.h"

class Pair
{
public:
    Point p1;
    Point p2;

    Pair();
    Pair(Point first, Point second);
    double getDistance() const;
};

#endif
