// Exercise 4.14 - Decimal to hex

#include <iostream>
#include <cctype>

int main()
{
    std::cout << "Enter a decimal value (0 to 15): ";
    int decimalValue;
    std::cin >> decimalValue;

    if (decimalValue <= 15 && decimalValue >= 10)
    {
        char hexValue = static_cast<char>('A' + (decimalValue - 10));
        std::cout << "The hex value is " << hexValue << std::endl;
    }
    else if (decimalValue <= 10 && decimalValue >= 0)
    {
        std::cout << "The hex value is " << decimalValue << std::endl;
    }
    else
    {
        std::cout << decimalValue << " is an invalid input" << std::endl;
    }

    return 0;
}