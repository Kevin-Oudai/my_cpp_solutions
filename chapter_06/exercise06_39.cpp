// Exercise 6.39 - Octal to decimal

#include <iostream>
#include <cmath>

int octal2Dec(const int &octalNumber)
{
    int decimalNumber = 0;
    int input = octalNumber, a = 0;
    while (input > 0)
    {
        decimalNumber += (input % 10) * pow(8, a);
        input /= 10;
        a++;
    }
    return decimalNumber;
}

int main()
{
    std::cout << "Enter an octal number: ";
    int octalNumber;
    std::cin >> octalNumber;

    std::cout << "Decimal Equivalent: " << octal2Dec(octalNumber) << std::endl;
    return 0;
}