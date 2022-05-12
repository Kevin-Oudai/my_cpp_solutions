// Exercise 6.8 - Conversion between Millimeters and Inches

#include <iostream>
#include <iomanip>

double millimetersToInches(double millimeters)
{
    return (millimeters * 0.039);
}

double inchesToMillimeters(double inches)
{
    return (inches / 0.039);
}

int main()
{
    std::cout << std::setw(14) << std::left << "Millimeters"
              << std::setw(9) << "Inches"
              << std::setw(4) << "|"
              << std::setw(9) << "Inches"
              << std::setw(14) << "Millimeters" << std::endl;

    for (int i = 1; i <= 50; i++)
    {
        std::cout << std::setw(14) << std::left << (i * 2)
                  << std::setw(9) << millimetersToInches(i * 2)
                  << std::setw(4) << "|"
                  << std::setw(9) << i
                  << std::setw(14) << inchesToMillimeters(i) << std::endl;
    }
    return 0;
}