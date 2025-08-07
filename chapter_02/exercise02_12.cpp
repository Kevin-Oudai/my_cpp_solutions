#include <iostream>
#include <cmath>

int main()
{
    double speed, acceleration, length;
    std::cout << "Enter the speed and acceleration: ";
    std::cin >> speed >> acceleration;
    length = pow(speed, 2) / (2 * acceleration);
    std::cout << "The minimum runway length for this airplane is " << length << std::endl;
    return 0;
}