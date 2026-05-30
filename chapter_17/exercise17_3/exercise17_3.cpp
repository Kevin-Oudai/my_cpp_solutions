#include <iostream>
#include "GcdCalculator.h"

int main()
{
    int m;
    int n;
    std::cout << "Enter two integers: ";
    std::cin >> m >> n;

    GcdCalculator calculator;
    std::cout << "The GCD is " << calculator.gcd(m, n) << std::endl;

    return 0;
}
