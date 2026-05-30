#include <iostream>
#include <string>
#include "HexDecimalConverter.h"

int main()
{
    std::string hexString;
    std::cout << "Enter a hex string: ";
    std::cin >> hexString;

    HexDecimalConverter converter;
    std::cout << "The decimal value is "
              << converter.hexToDecimal(hexString) << std::endl;

    return 0;
}
