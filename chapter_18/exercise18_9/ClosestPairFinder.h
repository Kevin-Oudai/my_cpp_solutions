#ifndef CLOSESTPAIRFINDER_H
#define CLOSESTPAIRFINDER_H

#include <vector>
#include "Pair.h"
#include "Point.h"

class ClosestPairFinder
{
public:
    Pair* getClosestPair(std::vector<std::vector<double> > points);
    Pair* getClosestPair(std::vector<Point>& points);
    double distance(std::vector<Point>& pointsOrderedOnX, int low, int high,
        std::vector<Point>& pointsOrderedOnY);
    double distance(Point& p1, Point& p2) const;
    double distance(double x1, double y1, double x2, double y2) const;

private:
    Pair closestPair;
    bool hasPair;

    void sortOnX(std::vector<Point>& points) const;
    void sortOnY(std::vector<Point>& points) const;
    void updateClosest(Point& p1, Point& p2);
    double bruteForce(std::vector<Point>& pointsOrderedOnX, int low, int high);
};

#endif
