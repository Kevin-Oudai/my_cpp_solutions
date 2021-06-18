// Exercise 5.56 - Corner Point Coordinates
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    const double PI = 3.14159;
    int angle = 0, sides;
    double radius, x, y, theta;

    std::cout << "Enter the number of the sides: ";
    std::cin >> sides;

    std::cout << "Enter the radius of the bounding circle: ";
    std::cin >> radius;

    std::cout << "The coordinates of the points on the polygon are \n";
    while (angle < 360)
    {
        theta = angle * PI / 180;
        x = radius * cos(theta);
        y = radius * sin(theta);
        std::cout << "(" << x << ", " << y << ")\n";
        angle += (360 / sides);
    }
    return 0;
}