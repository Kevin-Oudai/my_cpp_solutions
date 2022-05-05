#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double x1, x2, y1, y2, distance;

    std::cout << "Enter x1 and y1: ";
    std::cin >> x1 >> y1;
    std::cout << "Enter x2 and y2: ";
    std::cin >> x2 >> y2;
    distance = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
    std::cout << std::setprecision(15) << std::showpoint << std::fixed;
    std::cout << "The distance between the two points is " << distance << std::endl;
    return 0;
}