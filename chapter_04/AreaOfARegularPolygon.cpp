#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double side, numberOfSides, area;
    const double PI = 3.14159;
    std::cout << "Enter the number of sides: ";
    std::cin >> numberOfSides;
    std::cout << "Enter the side: ";
    std::cin >> side;

    area = (numberOfSides * pow(side, 2)) / (4 * tan(PI / numberOfSides));

    std::cout << std::setprecision(2) << std::showpoint << std::fixed;
    std::cout << "The area of the polygon is " << area << std::endl;

    return 0;
}