#ifndef BINARYFORMATEXCEPTION_H
#define BINARYFORMATEXCEPTION_H

#include <stdexcept>
#include <string>

class BinaryFormatException : public std::invalid_argument
{
public:
    BinaryFormatException();
    BinaryFormatException(const std::string &binaryString);
};

#endif
