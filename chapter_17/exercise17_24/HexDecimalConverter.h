#ifndef HEXDECIMALCONVERTER_H
#define HEXDECIMALCONVERTER_H

#include <string>

class HexDecimalConverter
{
public:
    int hexToDecimal(const std::string &hexString) const;

private:
    int hexToDecimal(const std::string &hexString, int index) const;
    int hexValue(char ch) const;
};

#endif
