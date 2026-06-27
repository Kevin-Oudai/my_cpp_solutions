#include "HexToDecimalConverter.h"
#include "HexFormatException.h"
#include <cctype>
#include <iostream>

void HexToDecimalConverter::run() const
{
    std::cout << "Enter a hex number: ";
    std::string hex;
    std::cin >> hex;

    try
    {
        int decimalValue = hex2Dec(hex);
        std::cout << "The decimal value for hex number " << hex
                  << " is " << decimalValue << std::endl;
    }
    catch (const HexFormatException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

int HexToDecimalConverter::hex2Dec(const std::string &hexString) const
{
    if (!isHexString(hexString))
    {
        throw HexFormatException(hexString);
    }

    int decimalValue = 0;
    for (unsigned int i = 0; i < hexString.size(); i++)
    {
        decimalValue = decimalValue * 16 + hexCharToDecimal(hexString[i]);
    }
    return decimalValue;
}

int HexToDecimalConverter::hexCharToDecimal(char ch) const
{
    ch = static_cast<char>(std::toupper(ch));
    if (ch >= 'A' && ch <= 'F')
    {
        return 10 + ch - 'A';
    }
    return ch - '0';
}

bool HexToDecimalConverter::isHexString(const std::string &hexString) const
{
    if (hexString.length() == 0)
    {
        return false;
    }

    for (unsigned int i = 0; i < hexString.length(); i++)
    {
        char ch = static_cast<char>(std::toupper(hexString[i]));
        if (!((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F')))
        {
            return false;
        }
    }

    return true;
}
