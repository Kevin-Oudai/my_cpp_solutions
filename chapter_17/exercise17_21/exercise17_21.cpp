#include <iostream>
#include "DecimalBinaryConverter.h"

int main()
{
    int value;
    std::cout << "Enter a decimal number: ";
    std::cin >> value;

    DecimalBinaryConverter converter;
    std::cout << "The binary value is " << converter.decimalToBinary(value) << std::endl;

    return 0;
}
