// Exercise 4.2 - Geometry: great circle distance

#include <iostream>
#include <cmath>

int main()
{
    const double PI = 3.1415926;
    const double EARTH_RADIUS = 6378.1; // km

    std::cout << "Enter point 1 (latitude and longitude) in degrees: ";
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1;

    std::cout << "Enter point 2 (latitude and longitude) in degrees: ";
    std::cin >> x2 >> y2;

    x1 *= PI / 180;
    x2 *= PI / 180;
    y1 *= PI / 180;
    y2 *= PI / 180;

    double distance = EARTH_RADIUS * acos(sin(x1) * sin(x2) + cos(x1) * cos(x2) * cos(y1 - y2));
    std::cout << "The distance between the two points is " << distance << std::endl;
    return 0;
}