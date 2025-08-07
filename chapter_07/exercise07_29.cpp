// Exercise 7.29 - Area of a polygon

#include <iostream>
#include <cmath>

double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double side1, side2, side3, area, s;

    side1 = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
    side2 = pow(pow(x2 - x3, 2) + pow(y2 - y3, 2), 0.5);
    side3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);

    s = (side1 + side2 + side3) / 2;

    area = pow(s * (s - side1) * (s - side2) * (s - side3), 0.5);

    return area;
}

int main()
{
    double points[12] = {};
    std::cout << "Enter the coordinates of six points: " << std::endl;
    for (int i = 0; i < 12; i++)
    {
        std::cin >> points[i];
    }
    double totalArea = 0;
    for (int i = 2; i < 10; i += 2)
    {
        totalArea += areaOfTriangle(points[0], points[1], points[i], points[i + 1], points[i + 2], points[i + 3]);
    }
    std::cout << "The total area is " << totalArea << std::endl;
    return 0;
}