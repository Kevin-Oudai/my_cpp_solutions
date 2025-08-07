#include <iostream>
#include <cmath>

int main()
{
    double x, y, distance;
    double radius = 10;
    std::cout << "Enter a point with two coordinates: ";
    std::cin >> x >> y;

    distance = pow(pow(x, 2) + pow(y, 2), 0.5);
    if (distance > radius)
    {
        std::cout << "Point (" << x << ", " << y << ") is not in the circle" << std::endl;
    }
    else if (distance < radius)
    {
        std::cout << "Point (" << x << ", " << y << ") is in the circle" << std::endl;
    }
    else
        std::cout << "Point (" << x << ", " << y << ") is on the circle" << std::endl;

    return 0;
}