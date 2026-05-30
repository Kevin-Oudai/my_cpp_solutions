#include <iostream>
#include <vector>
#include "ClosestPairFinder.h"

int main()
{
    std::cout << "Enter the number of points: ";
    int count;
    std::cin >> count;

    std::vector<Point> points;
    std::cout << "Enter " << count << " points: ";
    for (int i = 0; i < count; i++)
    {
        double x;
        double y;
        std::cin >> x >> y;
        points.push_back(Point(x, y));
    }

    ClosestPairFinder finder;
    Pair* pair = finder.getClosestPair(points);

    if (pair == 0)
    {
        std::cout << "At least two points are required" << std::endl;
        return 0;
    }

    std::cout << "The closest two points are ("
        << pair->p1.getX() << ", " << pair->p1.getY() << ") and ("
        << pair->p2.getX() << ", " << pair->p2.getY() << ")" << std::endl;
    std::cout << "Their distance is " << pair->getDistance() << std::endl;

    delete pair;
    return 0;
}
