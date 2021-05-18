#include <iostream>

int main()
{
    double lowerX = 0;
    double lowerY = 0;
    double upperX = 200;

    std::cout << "Enter a point's x- and y-coordinates: ";
    double x, y;
    std::cin >> x >> y;

    double upperY = -0.5 * x + 100;

    bool inXRange = x > lowerX && x < upperX;
    bool inYRange = y > lowerY && y < upperY;

    if (inXRange && inYRange)
    {
        std::cout << "The point is in the triangle" << std::endl;
    }
    else
    {
        std::cout << "The point is not in the triangle" << std::endl;
    }

    return 0;
}