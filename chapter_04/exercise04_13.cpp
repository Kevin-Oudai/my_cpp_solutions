// Listing 4.6 - HexDigit2Dec.cpp

#include <iostream>
#include <cctype>

int main()
{
    std::cout << "Enter a hex digit: ";
    char hexDigit;
    std::cin >> hexDigit;

    hexDigit = toupper(hexDigit);
    if (hexDigit <= 'F' && hexDigit >= 'A')
    {
        int value = 10 + hexDigit - 'A';
        std::cout << "The decimal value for hex digit "
                  << hexDigit << " is " << value << std::endl;
    }
    else if (isdigit(hexDigit))
    {
        std::cout << "The decimal value for hex digit "
                  << hexDigit << " is " << hexDigit << std::endl;
    }
    else
    {
        std::cout << hexDigit << " is an invalid input" << std::endl;
    }

    return 0;
}