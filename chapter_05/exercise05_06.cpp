// Exercise 5.6 - Conversion from meters to feet

#include <iostream>
#include <iomanip>

int main()
{
    const double METERS_TO_FEET = 3.280;
    int startValueMeters = 1;
    int meterIncrement = 1;
    int startValueFeet = 3;
    int feetIncrement = 3;
    std::cout << "Meters     Feet    |   Feet     Meters" << std::endl;
    while (startValueMeters <= 15)
    {
        std::cout << std::setw(11) << std::left << startValueMeters
                  << std::setprecision(3) << std::fixed << std::showpoint
                  << std::setw(8) << (startValueMeters * METERS_TO_FEET)
                  << std::setw(4) << "|"
                  << std::setw(9) << startValueFeet
                  << (startValueFeet / METERS_TO_FEET)
                  << std::endl;
        startValueMeters += meterIncrement;
        startValueFeet += feetIncrement;
    }

    return 0;
}