#include <iostream>
#include <iomanip>

int main()
{
    double M, finalTemperature, initialTemperature, Q;

    std::cout << "Enter the amount of water in kilograms: ";
    std::cin >> M;
    std::cout << "Enter the initial temperature: ";
    std::cin >> initialTemperature;
    std::cout << "Enter the final Temperature: ";
    std::cin >> finalTemperature;
    Q = M * (finalTemperature - initialTemperature) * 4184;
    std::cout << std::setprecision(1) << std::showpoint << std::fixed;
    std::cout << "The energy needed is " << Q << std::endl;
    return 0;
}