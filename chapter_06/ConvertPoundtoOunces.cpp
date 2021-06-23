// Exercise 6.9 - Conversions between Pounds and Ounces
#include <iostream>
#include <iomanip>

double poundsToOunces(double pounds)
{
    double ounces = pounds * 16;
    return ounces;
}

double ouncesToPounds(double ounces)
{
    double pound = ounces * 0.0625;
    return pound;
}

int main()
{
    std::cout << std::setw(9) << std::left << "Pounds"
              << std::setw(9) << "Ounces"
              << std::setw(4) << "|"
              << std::setw(9) << "Ounces"
              << std::setw(6) << "Pounds" << std::endl;
    for (int i = 1; i <= 10; i++)
    {
        std::cout << std::setw(9) << std::left << i + 10
                  << std::setw(9) << poundsToOunces(i + 10)
                  << std::setw(4) << "|"
                  << std::setw(9) << i
                  << std::setw(6) << ouncesToPounds(i) << std::endl;
    }

    return 0;
}