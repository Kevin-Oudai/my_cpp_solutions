#include <iostream>
#include "Rational.h"

int main()
{
    double sum = 0;
    for (int i = 1; i <= 99; i++)
    {
        Rational term(i, i + 1);
        sum += term.toDouble();
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    std::cout << "Series sum (1/2 + 2/3 + ... + 99/100): " << sum << std::endl;

    return 0;
}
