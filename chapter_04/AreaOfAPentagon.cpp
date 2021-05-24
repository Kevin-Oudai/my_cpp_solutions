// Exercise 4.1 - Geometry: area of a pentagon

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    const double PI = 3.1415926;
    std::cout << "Enter the length from the center to a vertex: ";
    double radius;
    std::cin >> radius;

    double side = 2 * radius * sin(PI / 5);
    double area = (5 * pow(side, 2)) / (4 * tan(PI / 5));

    std::cout << std::setprecision(2) << std::showpoint << std::fixed;
    std::cout << "The area of the pentagon is " << area << std::endl;
    return 0;
}