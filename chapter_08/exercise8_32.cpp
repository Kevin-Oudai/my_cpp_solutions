#include <iostream>
#include <cmath>

const int SIZE = 2;

double getTriangleArea(const double points[][SIZE])
{
    double x1, y1, x2, y2, x3, y3, side1, side2, side3, area, s;
    x1 = points[0][0];
    y1 = points[0][1];
    x2 = points[1][0];
    y2 = points[1][1];
    x3 = points[2][0];
    y3 = points[2][1];

    side1 = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
    side2 = pow(pow(x2 - x3, 2) + pow(y2 - y3, 2), 0.5);
    side3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);

    s = (side1 + side2 + side3) / 2;

    area = pow(s * (s - side1) * (s - side2) * (s - side3), 0.5);
    return area;
}

int main()
{
    double points[3][2] = {};
    std::cout << "Enter x1, y1, x2, y2, x3, y3: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cin >> points[i][j];
        }
    }
    double area = getTriangleArea(points);
    if (area == 0)
    {
        std::cout << "The three points are on the same line." << std::endl;
    }
    else
    {
        std::cout << "The area of the triangle is " << area << std::endl;
    }

    return 0;
}