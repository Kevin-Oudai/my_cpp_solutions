// Listing 5.10 - GreatestCommonDivisor.cpp

#include <iostream>

int main()
{
    std::cout << "Enter first integer: ";
    int n1;
    std::cin >> n1;

    std::cout << "Enter second integer: ";
    int n2;
    std::cin >> n2;

    int gcd = 1;
    int k = 2;
    while (k <= n1 && k <= n2)
    {
        if (n1 % k == 0 && n2 % k == 0)
            gcd = k;
        k++;
    }

    std::cout << "The greatest common divisor for " << n1 << " and "
              << n2 << " is " << gcd << std::endl;

    return 0;
}