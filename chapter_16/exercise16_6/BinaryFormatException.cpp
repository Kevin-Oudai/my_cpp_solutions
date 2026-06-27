#include "BinaryFormatException.h"

BinaryFormatException::BinaryFormatException()
    : std::invalid_argument("The string is not a binary string")
{
}

BinaryFormatException::BinaryFormatException(const std::string &binaryString)
    : std::invalid_argument("The string is not a binary string: " + binaryString)
{
}
