// Exercise 5.3 - Conversion from millimeters to inches

#include <iostream>
#include <iomanip>

int main()
{
    const double MILLIMETERS_TO_INCHES = 0.039;
    int startValue = 2;
    int increment = 2;
    std::cout << "Millimeters     Inches" << std::endl;
    while (startValue <= 98)
    {
        std::cout << std::setw(16) << std::left << startValue
                  << std::setprecision(3) << std::fixed << std::showpoint
                  << (startValue * MILLIMETERS_TO_INCHES) << std::endl;
        startValue += increment;
    }

    return 0;
}