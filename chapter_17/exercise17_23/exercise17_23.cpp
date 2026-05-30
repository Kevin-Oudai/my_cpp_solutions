#include <iostream>
#include <string>
#include "BinaryDecimalConverter.h"

int main()
{
    std::string binaryString;
    std::cout << "Enter a binary string: ";
    std::cin >> binaryString;

    BinaryDecimalConverter converter;
    std::cout << "The decimal value is "
              << converter.binaryToDecimal(binaryString) << std::endl;

    return 0;
}
