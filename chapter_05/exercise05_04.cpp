// Exercise 5.4 - Conversion from meters to feet

#include <iostream>
#include <iomanip>

int main()
{
    const double METER_TO_FEET = 3.280;
    int startValue = 1;
    int increment = 1;
    int endValue = 15;
    std::cout << "Meters     Feet" << std::endl;
    while (startValue <= endValue)
    {
        std::cout << std::setw(11) << std::left << startValue
                  << std::setprecision(3) << std::fixed << std::showpoint
                  << (startValue * METER_TO_FEET) << std::endl;
        startValue += increment;
    }

    return 0;
}