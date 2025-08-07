// Exercise 5.8 - Use the exp function
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    int startValue = 0;
    int increment = 1;
    int endValue = 10;

    std::cout << "Number     Exponent" << std::endl;

    while (startValue <= endValue)
    {
        std::cout << std::left << std::setw(11) << startValue
                  << std::setw(6) << exp(startValue) << std::endl;
        startValue += increment;
    }

    return 0;
}