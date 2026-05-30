#include <iostream>
#include <vector>
#include "GrahamHull.h"

int main()
{
    std::cout << "Enter the number of points: ";
    int count;
    std::cin >> count;

    std::vector<MyPoint> points;
    std::cout << "Enter " << count << " points: ";
    for (int i = 0; i < count; i++)
    {
        double x;
        double y;
        std::cin >> x >> y;
        points.push_back(MyPoint(x, y));
    }

    GrahamHull hullFinder;
    std::vector<MyPoint> hull = hullFinder.getConvexHull(points);

    std::cout << "The convex hull is" << std::endl;
    for (int i = 0; i < static_cast<int>(hull.size()); i++)
        std::cout << "(" << hull[i].x << ", " << hull[i].y << ") ";
    std::cout << std::endl;

    return 0;
}
