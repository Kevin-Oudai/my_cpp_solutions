#include "BinaryDecimalConverter.h"

int BinaryDecimalConverter::binaryToDecimal(const std::string &binaryString) const
{
    return binaryToDecimal(binaryString, 0);
}

int BinaryDecimalConverter::binaryToDecimal(const std::string &binaryString, int index) const
{
    if (index == static_cast<int>(binaryString.length()))
    {
        return 0;
    }
    return (binaryString[index] - '0') *
               (1 << (static_cast<int>(binaryString.length()) - index - 1)) +
           binaryToDecimal(binaryString, index + 1);
}
