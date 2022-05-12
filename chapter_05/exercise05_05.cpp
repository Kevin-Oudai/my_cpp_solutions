// Exercise 5.5 - Conversion from millimeters to inches and inches to millimeters

#include <iostream>
#include <iomanip>

int main()
{
    const double MILLIMETERS_TO_INCHES = 0.039;
    int startValueMillimeters = 2;
    int millimeterIncrement = 2;
    int startValueInches = 1;
    int inchIncrement = 1;
    std::cout << "Millimeters     Inches   |   Inches     Millimeters" << std::endl;
    while (startValueMillimeters <= 100)
    {
        std::cout << std::setw(16) << std::left << startValueMillimeters
                  << std::setprecision(3) << std::fixed << std::showpoint
                  << std::setw(9) << (startValueMillimeters * MILLIMETERS_TO_INCHES)
                  << std::setw(4) << "|"
                  << std::setw(11) << startValueInches
                  << (startValueInches / MILLIMETERS_TO_INCHES)
                  << std::endl;
        startValueMillimeters += millimeterIncrement;
        startValueInches += inchIncrement;
    }

    return 0;
}