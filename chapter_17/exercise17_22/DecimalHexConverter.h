#ifndef DECIMALHEXCONVERTER_H
#define DECIMALHEXCONVERTER_H

#include <string>

class DecimalHexConverter
{
public:
    std::string decimalToHex(int value) const;

private:
    char hexDigit(int value) const;
};

#endif
