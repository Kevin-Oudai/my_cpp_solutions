#include "GrahamHull.h"

double GrahamHull::crossProduct(const MyPoint& p0, const MyPoint& p1, const MyPoint& p2) const
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double GrahamHull::distanceSquared(const MyPoint& p1, const MyPoint& p2) const
{
    double xDifference = p1.x - p2.x;
    double yDifference = p1.y - p2.y;
    return xDifference * xDifference + yDifference * yDifference;
}

int GrahamHull::getLowestPointIndex(std::vector<MyPoint>& points) const
{
    int lowest = 0;
    for (int i = 1; i < static_cast<int>(points.size()); i++)
    {
        if (points[i].y < points[lowest].y ||
            (points[i].y == points[lowest].y && points[i].x < points[lowest].x))
            lowest = i;
    }

    return lowest;
}

void GrahamHull::sortByAngle(std::vector<MyPoint>& points, const MyPoint& start) const
{
    for (int i = 1; i < static_cast<int>(points.size()) - 1; i++)
    {
        int selected = i;
        for (int j = i + 1; j < static_cast<int>(points.size()); j++)
        {
            double turn = crossProduct(start, points[selected], points[j]);
            if (turn < 0 || (turn == 0 &&
                distanceSquared(start, points[j]) < distanceSquared(start, points[selected])))
                selected = j;
        }

        if (selected != i)
        {
            MyPoint temp = points[i];
            points[i] = points[selected];
            points[selected] = temp;
        }
    }
}

std::vector<MyPoint> GrahamHull::getConvexHull(std::vector<MyPoint>& s) const
{
    std::vector<MyPoint> hull;
    if (s.size() < 3)
        return s;

    std::vector<MyPoint> points = s;
    int startIndex = getLowestPointIndex(points);
    MyPoint temp = points[0];
    points[0] = points[startIndex];
    points[startIndex] = temp;

    sortByAngle(points, points[0]);

    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < static_cast<int>(points.size()); i++)
    {
        while (hull.size() >= 2)
        {
            MyPoint top = hull[hull.size() - 1];
            MyPoint nextToTop = hull[hull.size() - 2];
            if (crossProduct(nextToTop, top, points[i]) > 0)
                break;
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}
