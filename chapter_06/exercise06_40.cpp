// Exercise 6.40 - Binary to Octal

#include <iostream>
#include <string>
#include <cmath>

int binary2Dec(const std::string &binaryNumber)
{
    int decimalNumber = 0;
    int a = 0, binNum;
    for (int i = binaryNumber.length() - 1; i >= 0; i--)
    {
        binNum = binaryNumber.at(i) == '0' ? 0 : 1;
        decimalNumber += binNum * pow(2, a);
        a++;
    }

    return decimalNumber;
}

int stringToInt(std::string value)
{
    int number = 0;
    for (int i = 0; i < value.length(); i++)
    {
        number *= 10;
        number += static_cast<int>(value.at(i) - '0');
    }
    return number;
}

int dec2Octal(const int &decimal)
{
    std::string octal = "";
    int input = decimal;

    while (input > 0)
    {
        octal = static_cast<char>((input % 8) + '0') + octal;
        input /= 8;
    }

    return stringToInt(octal);
}

int bin2Octal(const std::string &binaryString)
{
    int decimal = binary2Dec(binaryString);
    int octal = dec2Octal(decimal);
    return octal;
}

int main()
{
    std::cout << "Enter a binary number: ";
    std::string binaryNumber;
    std::getline(std::cin, binaryNumber);

    std::cout << "Octal Equivalent: " << bin2Octal(binaryNumber) << std::endl;
}