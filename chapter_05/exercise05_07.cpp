// Exercise 5.7 - Use Trigonometric Functions
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    int increment = 10;
    int startValue = 0;
    int endValue = 60;
    double angle;
    std::cout << "Degree     Sin/Cos     Cos/Sin" << std::endl;
    while (startValue <= endValue)
    {
        angle = startValue * 3.14159 / 180;
        std::cout << std::setw(11) << std::left << std::setprecision(4) << std::fixed << std::showpoint
                  << startValue << std::setw(12) << (sin(angle) / cos(angle))
                  << (cos(angle) / sin(angle)) << std::endl;

        startValue += increment;
    }

    return 0;
}