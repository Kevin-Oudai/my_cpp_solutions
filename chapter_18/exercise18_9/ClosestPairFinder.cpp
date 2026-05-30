#include "ClosestPairFinder.h"
#include <cmath>

Pair* ClosestPairFinder::getClosestPair(std::vector<std::vector<double> > points)
{
    std::vector<Point> converted;
    for (int i = 0; i < static_cast<int>(points.size()); i++)
    {
        if (points[i].size() >= 2)
            converted.push_back(Point(points[i][0], points[i][1]));
    }

    return getClosestPair(converted);
}

Pair* ClosestPairFinder::getClosestPair(std::vector<Point>& points)
{
    if (points.size() < 2)
        return 0;

    std::vector<Point> pointsOrderedOnX = points;
    std::vector<Point> pointsOrderedOnY = points;
    sortOnX(pointsOrderedOnX);
    sortOnY(pointsOrderedOnY);

    hasPair = false;
    distance(pointsOrderedOnX, 0, static_cast<int>(pointsOrderedOnX.size()) - 1, pointsOrderedOnY);

    return new Pair(closestPair);
}

double ClosestPairFinder::distance(std::vector<Point>& pointsOrderedOnX, int low, int high,
    std::vector<Point>& pointsOrderedOnY)
{
    if (high - low <= 3)
        return bruteForce(pointsOrderedOnX, low, high);

    int mid = (low + high) / 2;
    double middleX = pointsOrderedOnX[mid].getX();

    std::vector<Point> leftOrderedOnY;
    std::vector<Point> rightOrderedOnY;
    for (int i = 0; i < static_cast<int>(pointsOrderedOnY.size()); i++)
    {
        if (pointsOrderedOnY[i].getX() < middleX ||
            (pointsOrderedOnY[i].getX() == middleX && pointsOrderedOnY[i].getY() <= pointsOrderedOnX[mid].getY()))
            leftOrderedOnY.push_back(pointsOrderedOnY[i]);
        else
            rightOrderedOnY.push_back(pointsOrderedOnY[i]);
    }

    double leftDistance = distance(pointsOrderedOnX, low, mid, leftOrderedOnY);
    double rightDistance = distance(pointsOrderedOnX, mid + 1, high, rightOrderedOnY);
    double bestDistance = leftDistance < rightDistance ? leftDistance : rightDistance;

    std::vector<Point> strip;
    for (int i = 0; i < static_cast<int>(pointsOrderedOnY.size()); i++)
    {
        if (fabs(pointsOrderedOnY[i].getX() - middleX) < bestDistance)
            strip.push_back(pointsOrderedOnY[i]);
    }

    for (int i = 0; i < static_cast<int>(strip.size()); i++)
    {
        for (int j = i + 1; j < static_cast<int>(strip.size()) &&
            strip[j].getY() - strip[i].getY() < bestDistance; j++)
        {
            double currentDistance = distance(strip[i], strip[j]);
            if (currentDistance < bestDistance)
            {
                bestDistance = currentDistance;
                updateClosest(strip[i], strip[j]);
            }
        }
    }

    return bestDistance;
}

double ClosestPairFinder::distance(Point& p1, Point& p2) const
{
    return distance(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}

double ClosestPairFinder::distance(double x1, double y1, double x2, double y2) const
{
    double xDifference = x1 - x2;
    double yDifference = y1 - y2;
    return sqrt(xDifference * xDifference + yDifference * yDifference);
}

void ClosestPairFinder::sortOnX(std::vector<Point>& points) const
{
    for (int i = 0; i < static_cast<int>(points.size()) - 1; i++)
    {
        int currentMinIndex = i;
        for (int j = i + 1; j < static_cast<int>(points.size()); j++)
        {
            if (points[j].getX() < points[currentMinIndex].getX() ||
                (points[j].getX() == points[currentMinIndex].getX() &&
                    points[j].getY() < points[currentMinIndex].getY()))
                currentMinIndex = j;
        }

        if (currentMinIndex != i)
        {
            Point temp = points[i];
            points[i] = points[currentMinIndex];
            points[currentMinIndex] = temp;
        }
    }
}

void ClosestPairFinder::sortOnY(std::vector<Point>& points) const
{
    for (int i = 0; i < static_cast<int>(points.size()) - 1; i++)
    {
        int currentMinIndex = i;
        for (int j = i + 1; j < static_cast<int>(points.size()); j++)
        {
            if (points[j].getY() < points[currentMinIndex].getY() ||
                (points[j].getY() == points[currentMinIndex].getY() &&
                    points[j].getX() < points[currentMinIndex].getX()))
                currentMinIndex = j;
        }

        if (currentMinIndex != i)
        {
            Point temp = points[i];
            points[i] = points[currentMinIndex];
            points[currentMinIndex] = temp;
        }
    }
}

void ClosestPairFinder::updateClosest(Point& p1, Point& p2)
{
    if (!hasPair || distance(p1, p2) < closestPair.getDistance())
    {
        closestPair = Pair(p1, p2);
        hasPair = true;
    }
}

double ClosestPairFinder::bruteForce(std::vector<Point>& pointsOrderedOnX, int low, int high)
{
    double bestDistance = 0;
    bool found = false;

    for (int i = low; i <= high; i++)
    {
        for (int j = i + 1; j <= high; j++)
        {
            double currentDistance = distance(pointsOrderedOnX[i], pointsOrderedOnX[j]);
            if (!found || currentDistance < bestDistance)
            {
                bestDistance = currentDistance;
                found = true;
                updateClosest(pointsOrderedOnX[i], pointsOrderedOnX[j]);
            }
        }
    }

    return bestDistance;
}
