// Exercise 6.41 - Octal to Binary

#include <iostream>
#include <string>
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

std::string dec2Binary(int decimal)
{
    std::string binary = "", digit;
    while (decimal > 0)
    {
        binary = ((decimal % 2 == 0) ? "0" : "1") + binary;
        decimal /= 2;
    }
    return binary;
}

std::string octal2Binary(const int &octalNumber)
{
    int decimal = octal2Dec(octalNumber);
    return dec2Binary(decimal);
}

int main()
{
    std::cout << "Enter an octal number: ";
    int octalNumber;
    std::cin >> octalNumber;

    std::cout << "Octal " << octalNumber << " is equivalent to binary " << octal2Binary(octalNumber) << std::endl;
    return 0;
}