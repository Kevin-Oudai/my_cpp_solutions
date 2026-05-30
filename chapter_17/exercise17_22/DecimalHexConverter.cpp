#include "DecimalHexConverter.h"

std::string DecimalHexConverter::decimalToHex(int value) const
{
    if (value < 16)
    {
        return std::string(1, hexDigit(value));
    }
    return decimalToHex(value / 16) + hexDigit(value % 16);
}

char DecimalHexConverter::hexDigit(int value) const
{
    return value < 10 ? static_cast<char>('0' + value)
                      : static_cast<char>('A' + value - 10);
}
