#include <iostream>
#include <cmath>

int main()
{
    double x, y, distance;
    double width = 10;
    double height = 5;
    std::cout << "Enter a point with two coordinates: ";
    std::cin >> x >> y;

    double upperX, upperY, lowerX, lowerY;
    upperX = width / 2;
    lowerX = -width / 2;
    upperY = height / 2;
    lowerY = -height / 2;

    bool inXrange = x <= upperX && x >= lowerX;
    bool inYrange = y <= upperY && y >= lowerY;

    if (inXrange && inYrange)
    {
        std::cout << "Point (" << x << ", " << y << ") is in the rectangle" << std::endl;
    }
    else
        std::cout << "Point (" << x << ", " << y << ") is not in the rectangle" << std::endl;

    return 0;
}