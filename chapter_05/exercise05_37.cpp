// Exercise 5.37 - Summation

#include <iostream>
#include <cmath>

int main()
{
    int b;
    double sum = 0;
    for (int a = 99; a >= 9; a -= 6)
    {
        b = a - 6;
        sum += (1.0 / (std::pow(a, 1.0 / 3) - std::pow(b, 1.0 / 3)));
    }
    std::cout << "Summation: " << sum << std::endl;
    return 0;
}