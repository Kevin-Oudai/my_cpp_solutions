#include "Pair.h"
#include <cmath>

Pair::Pair()
{
}

Pair::Pair(Point first, Point second)
{
    p1 = first;
    p2 = second;
}

double Pair::getDistance() const
{
    double xDifference = p1.getX() - p2.getX();
    double yDifference = p1.getY() - p2.getY();
    return sqrt(xDifference * xDifference + yDifference * yDifference);
}
