#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double side, area;
    const double PI = 3.14159;
    std::cout << "Enter the side: ";
    std::cin >> side;

    area = (6 * pow(side, 2)) / (4 * tan(PI / 6));

    std::cout << std::setprecision(2) << std::showpoint << std::fixed;
    std::cout << "The area of the hexagon is " << area << std::endl;

    return 0;
}