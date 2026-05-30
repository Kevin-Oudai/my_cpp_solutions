#include <iostream>
#include "DecimalHexConverter.h"

int main()
{
    int value;
    std::cout << "Enter a decimal number: ";
    std::cin >> value;

    DecimalHexConverter converter;
    std::cout << "The hex value is " << converter.decimalToHex(value) << std::endl;

    return 0;
}
