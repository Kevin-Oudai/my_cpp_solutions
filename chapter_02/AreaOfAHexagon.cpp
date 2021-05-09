#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    // I am not sure why I am getting 78.5918 instead of 78.5895
    double side, area;

    std::cout << "Enter the side: ";
    std::cin >> side;

    area = (3 * pow(3, 0.5) * pow(side, 2)) / 2;
    std::cout << std::setprecision(4) << std::showpoint << std::fixed;
    std::cout << "The area of the hexagon is " << area << std::endl;
    return 0;
}