// Listing 4.6 - HexDigit2Dec.cpp

#include <iostream>
#include <cctype>

int main()
{
    std::cout << "Enter a hex digit: ";
    char hexDigit;
    std::cin >> hexDigit;
    int value, binaryValue;

    hexDigit = toupper(hexDigit);
    if (hexDigit <= 'F' && hexDigit >= 'A')
    {
        value = 10 + hexDigit - 'A';
        binaryValue = value % 2;
        value /= 2;
        binaryValue = (10 * (value % 2)) + binaryValue;
        value /= 2;
        binaryValue = (100 * (value % 2)) + binaryValue;
        value /= 2;
        binaryValue = (1000 * (value % 2)) + binaryValue;
        std::cout << "The binary value is " << binaryValue << std::endl;
    }
    else if (isdigit(hexDigit))
    {
        value = static_cast<int>(hexDigit);
        binaryValue = value % 2;
        value /= 2;
        binaryValue = (10 * (value % 2)) + binaryValue;
        value /= 2;
        binaryValue = (100 * (value % 2)) + binaryValue;
        value /= 2;
        binaryValue = (1000 * (value % 2)) + binaryValue;
        std::cout << "The binary value is " << binaryValue << std::endl;
    }
    else
    {
        std::cout << hexDigit << " is an invalid input" << std::endl;
    }

    return 0;
}