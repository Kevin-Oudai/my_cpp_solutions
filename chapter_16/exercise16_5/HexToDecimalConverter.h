#ifndef HEXTODECIMALCONVERTER_H
#define HEXTODECIMALCONVERTER_H

#include <string>

class HexToDecimalConverter
{
public:
    void run() const;
    int hex2Dec(const std::string &hexString) const;

private:
    int hexCharToDecimal(char ch) const;
    bool isHexString(const std::string &hexString) const;
};

#endif
