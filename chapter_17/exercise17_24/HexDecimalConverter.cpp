#include "HexDecimalConverter.h"

int HexDecimalConverter::hexToDecimal(const std::string &hexString) const
{
    return hexToDecimal(hexString, 0);
}

int HexDecimalConverter::hexToDecimal(const std::string &hexString, int index) const
{
    if (index == static_cast<int>(hexString.length()))
    {
        return 0;
    }

    int power = 1;
    for (int i = index + 1; i < static_cast<int>(hexString.length()); i++)
    {
        power *= 16;
    }

    return hexValue(hexString[index]) * power + hexToDecimal(hexString, index + 1);
}

int HexDecimalConverter::hexValue(char ch) const
{
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    if (ch >= 'a' && ch <= 'f')
    {
        return ch - 'a' + 10;
    }
    return ch - 'A' + 10;
}
