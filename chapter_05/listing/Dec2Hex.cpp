// Listing 5.13 - Dec2Hex.cpp

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a decimal number: ";
    int decimal;
    std::cin >> decimal;

    std::string hex = "";

    while (decimal != 0)
    {
        int hexValue = decimal % 16;

        char hexChar = (hexValue <= 9 && hexValue >= 0) ? static_cast<char>(hexValue + '0') : static_cast<char>(hexValue - 10 + 'A');

        hex = hexChar + hex;
        decimal = decimal / 16;
    }

    std::cout << "The hex number is " << hex << std::endl;

    return 0;
}