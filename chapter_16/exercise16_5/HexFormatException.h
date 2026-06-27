#ifndef HEXFORMATEXCEPTION_H
#define HEXFORMATEXCEPTION_H

#include <stdexcept>
#include <string>

class HexFormatException : public std::invalid_argument
{
public:
    HexFormatException();
    HexFormatException(const std::string &hexString);
};

#endif
