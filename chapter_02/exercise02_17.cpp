#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double outsideTemp, speed, windChillTemp;

    std::cout << "Enter the temperature in Fahrenheit: ";
    std::cin >> outsideTemp;
    std::cout << "Enter the wind speed in miles per hour: ";
    std::cin >> speed;

    windChillTemp = 35.74 + 0.6215 * outsideTemp - 35.75 * pow(speed, 0.16) + 0.4275 * outsideTemp * pow(speed, 0.16);

    std::cout << std::setprecision(5) << std::showpoint << std::fixed;
    std::cout << "The wind chill index is " << windChillTemp << std::endl;
    return 0;
}