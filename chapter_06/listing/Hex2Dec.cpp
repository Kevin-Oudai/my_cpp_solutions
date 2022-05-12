// Listing 6.18
#include <iostream>
#include <string>
#include <cctype>

int hex2Dec(const std::string &hex);
int hexCharToDecimal(char ch);

int main()
{
    std::cout << "Enter a hex number: ";
    std::string hex;
    std::cin >> hex;

    std::cout << "The decimal value for hex number " << hex
              << " is " << hex2Dec(hex) << std::endl;

    return 0;
}

int hex2Dec(const std::string &hex)
{
    int decimalValue = 0;
    for (unsigned i = 0; i < hex.size(); i++)
    {
        decimalValue = decimalValue * 16 + hexCharToDecimal(hex[i]);
    }
    return decimalValue;
}

int hexCharToDecimal(char ch)
{
    ch = toupper(ch);
    if (ch >= 'A' && ch <= 'F')
    {
        return 10 + ch - 'A';
    }
    else
        return ch - '0';
}