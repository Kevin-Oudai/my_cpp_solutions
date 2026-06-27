#ifndef CLOSESTPAIR_H
#define CLOSESTPAIR_H

#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <vector>

class Point
{
public:
    double x;
    double y;

    Point()
    {
        x = 0;
        y = 0;
    }

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

class PointByX
{
public:
    bool operator()(const Point& p1, const Point& p2) const
    {
        if (p1.x != p2.x)
            return p1.x < p2.x;

        return p1.y < p2.y;
    }
};

class PointByY
{
public:
    bool operator()(const Point& p1, const Point& p2) const
    {
        if (p1.y != p2.y)
            return p1.y < p2.y;

        return p1.x < p2.x;
    }
};

class ClosestPairResult
{
public:
    Point p1;
    Point p2;
    double distance;

    ClosestPairResult()
    {
        distance = std::numeric_limits<double>::infinity();
    }
};

inline double distanceBetween(const Point& p1, const Point& p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

inline ClosestPairResult closestPair(std::vector<Point> points)
{
    ClosestPairResult result;

    if (points.size() < 2)
        return result;

    std::sort(points.begin(), points.end(), PointByX());
    std::set<Point, PointByY> active;
    int left = 0;

    for (int i = 0; i < static_cast<int>(points.size()); i++)
    {
        Point current = points[i];

        while (left < i && current.x - points[left].x > result.distance)
        {
            active.erase(points[left]);
            left++;
        }

        Point lower(current.x, current.y - result.distance);
        Point upper(current.x, current.y + result.distance);
        std::set<Point, PointByY>::iterator begin = active.lower_bound(lower);
        std::set<Point, PointByY>::iterator end = active.upper_bound(upper);

        for (std::set<Point, PointByY>::iterator iterator = begin; iterator != end; iterator++)
        {
            double d = distanceBetween(current, *iterator);
            if (d < result.distance)
            {
                result.distance = d;
                result.p1 = current;
                result.p2 = *iterator;
            }
        }

        active.insert(current);
    }

    return result;
}

#endif
