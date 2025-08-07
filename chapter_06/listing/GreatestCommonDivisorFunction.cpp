// Listing 6.4 - GreatestCommonDivisorFunction.cpp

#include <iostream>

int gcd(int n1, int n2)
{
    int gcd = 1;
    int k = 2;

    while (k <= n1 && k <= n2)
    {
        if (n1 % k == 0 && n2 % k == 0)
        {
            gcd = k;
        }
        k++;
    }
    return gcd;
}

int main()
{
    std::cout << "Enter first integer: ";
    int n1;
    std::cin >> n1;

    std::cout << "Enter second integer: ";
    int n2;
    std::cin >> n2;

    std::cout << "The greatest common divisor for " << n1
              << " and " << n2 << " is " << gcd(n1, n2) << std::endl;

    return 0;
}