#ifndef BINARYTOOCTALCONVERTER_H
#define BINARYTOOCTALCONVERTER_H

#include <string>

class BinaryToOctalConverter
{
public:
    void run() const;
    int bin2Octal(const std::string &binaryString) const;

private:
    int binary2Dec(const std::string &binaryString) const;
    int dec2Octal(int decimal) const;
    bool isBinaryString(const std::string &binaryString) const;
};

#endif
