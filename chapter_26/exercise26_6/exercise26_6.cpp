#include "../ClosestPair.h"
#include <iostream>

int main()
{
    std::vector<Point> points;
    points.push_back(Point(0, 0));
    points.push_back(Point(5, 4));
    points.push_back(Point(3, 1));
    points.push_back(Point(1, 1));
    points.push_back(Point(8, 7));

    ClosestPairResult result = closestPair(points);

    std::cout << "Closest pair: (" << result.p1.x << ", " << result.p1.y << ") and ("
        << result.p2.x << ", " << result.p2.y << ")" << std::endl;
    std::cout << "Distance: " << result.distance << std::endl;

    return 0;
}
