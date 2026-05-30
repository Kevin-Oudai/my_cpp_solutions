#ifndef BINARYDECIMALCONVERTER_H
#define BINARYDECIMALCONVERTER_H

#include <string>

class BinaryDecimalConverter
{
public:
    int binaryToDecimal(const std::string &binaryString) const;

private:
    int binaryToDecimal(const std::string &binaryString, int index) const;
};

#endif
