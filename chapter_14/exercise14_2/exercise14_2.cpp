#include <iostream>
#include "Rational.h"

int main()
{
    Rational sum(0, 1);
    for (int i = 1; i <= 99; i++)
    {
        sum += Rational(i, i + 1);
    }

    std::cout << "Series sum (1/2 + 2/3 + ... + 99/100): " << sum << std::endl;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    std::cout << "As decimal: " << sum.toDouble() << std::endl;

    return 0;
}
