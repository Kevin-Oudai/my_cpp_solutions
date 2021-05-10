#include <iostream>
#include <iomanip>

int main()
{
    double distance, milesPerGallon, pricePerGallon, cost;
    std::cout << "Enter the driving distance: ";
    std::cin >> distance;
    std::cout << "Enter miles per gallon: ";
    std::cin >> milesPerGallon;
    std::cout << "Enter price per gallon: ";
    std::cin >> pricePerGallon;

    cost = distance / milesPerGallon * pricePerGallon;
    std::cout << std::setprecision(2) << std::showpoint << std::fixed;
    std::cout << "The driving cost is $" << cost << std::endl;
    return 0;
}