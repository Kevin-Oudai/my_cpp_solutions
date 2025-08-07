#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double x1, y1, x2, y2, x3, y3, side1, side2, side3, area, s;

    std::cout << "Enter three points for a triangle: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    side1 = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
    side2 = pow(pow(x2 - x3, 2) + pow(y2 - y3, 2), 0.5);
    side3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);

    s = (side1 + side2 + side3) / 2;

    area = pow(s * (s - side1) * (s - side2) * (s - side3), 0.5);
    std::cout << "The area of the triangle is " << area << std::endl;

    return 0;
}