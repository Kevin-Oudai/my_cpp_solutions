#include "HexFormatException.h"

HexFormatException::HexFormatException()
    : std::invalid_argument("The string is not a hex string")
{
}

HexFormatException::HexFormatException(const std::string &hexString)
    : std::invalid_argument("The string is not a hex string: " + hexString)
{
}
