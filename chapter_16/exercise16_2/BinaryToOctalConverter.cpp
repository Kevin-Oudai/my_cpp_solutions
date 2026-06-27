#include "BinaryToOctalConverter.h"
#include <iostream>
#include <stdexcept>

void BinaryToOctalConverter::run() const
{
    std::cout << "Enter a binary number: ";
    std::string binaryNumber;
    std::cin >> binaryNumber;

    try
    {
        int octal = bin2Octal(binaryNumber);
        std::cout << "Octal Equivalent: " << octal << std::endl;
    }
    catch (const std::invalid_argument &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

int BinaryToOctalConverter::bin2Octal(const std::string &binaryString) const
{
    if (!isBinaryString(binaryString))
    {
        throw std::invalid_argument("The string is not a binary string");
    }

    return dec2Octal(binary2Dec(binaryString));
}

int BinaryToOctalConverter::binary2Dec(const std::string &binaryString) const
{
    int decimal = 0;
    for (unsigned int i = 0; i < binaryString.length(); i++)
    {
        decimal = decimal * 2 + binaryString[i] - '0';
    }
    return decimal;
}

int BinaryToOctalConverter::dec2Octal(int decimal) const
{
    int octal = 0;
    int place = 1;

    do
    {
        octal += (decimal % 8) * place;
        decimal /= 8;
        place *= 10;
    } while (decimal > 0);

    return octal;
}

bool BinaryToOctalConverter::isBinaryString(const std::string &binaryString) const
{
    if (binaryString.length() == 0)
    {
        return false;
    }

    for (unsigned int i = 0; i < binaryString.length(); i++)
    {
        if (binaryString[i] != '0' && binaryString[i] != '1')
        {
            return false;
        }
    }

    return true;
}
