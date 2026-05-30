#include "DecimalBinaryConverter.h"

std::string DecimalBinaryConverter::decimalToBinary(int value) const
{
    if (value < 2)
    {
        return std::string(1, static_cast<char>('0' + value));
    }
    return decimalToBinary(value / 2) + static_cast<char>('0' + value % 2);
}
