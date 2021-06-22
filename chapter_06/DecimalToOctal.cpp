// Exercise 6.38 - Decimal to Octal

#include <iostream>
#include <string>

int reverseNumber(int extract)
{
    int reverseNumber = 0;
    while (extract > 0)
    {
        reverseNumber = (reverseNumber * 10) + (extract % 10);
        extract /= 10;
    }
    return reverseNumber;
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

int main()
{
    (dec2Octal(32) == 40)
        ? std::cout << "The function works.\n"
        : std::cout << "There is an error. Got: " << dec2Octal(32) << std::endl;
    return 0;
}