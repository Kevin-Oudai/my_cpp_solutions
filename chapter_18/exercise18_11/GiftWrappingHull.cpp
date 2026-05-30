#include "GiftWrappingHull.h"

double GiftWrappingHull::crossProduct(const MyPoint& p0, const MyPoint& p1, const MyPoint& p2) const
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double GiftWrappingHull::distanceSquared(const MyPoint& p1, const MyPoint& p2) const
{
    double xDifference = p1.x - p2.x;
    double yDifference = p1.y - p2.y;
    return xDifference * xDifference + yDifference * yDifference;
}

std::vector<MyPoint> GiftWrappingHull::getConvexHull(std::vector<MyPoint>& s) const
{
    std::vector<MyPoint> hull;
    if (s.size() < 3)
        return s;

    int leftMost = 0;
    for (int i = 1; i < static_cast<int>(s.size()); i++)
    {
        if (s[i].x < s[leftMost].x || (s[i].x == s[leftMost].x && s[i].y < s[leftMost].y))
            leftMost = i;
    }

    int p = leftMost;
    do
    {
        hull.push_back(s[p]);
        int q = (p + 1) % static_cast<int>(s.size());

        for (int i = 0; i < static_cast<int>(s.size()); i++)
        {
            double turn = crossProduct(s[p], s[q], s[i]);
            if (turn < 0 || (turn == 0 && distanceSquared(s[p], s[i]) > distanceSquared(s[p], s[q])))
                q = i;
        }

        p = q;
    }
    while (p != leftMost);

    return hull;
}
