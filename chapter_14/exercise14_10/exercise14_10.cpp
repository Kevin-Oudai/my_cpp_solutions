#include <iostream>
#include <string>
#include "DecimalToFractionConverter.h"

int main()
{
    std::string decimal;
    DecimalToFractionConverter converter;

    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;

    Rational fraction = converter.convert(decimal);
    std::cout << "The fraction number is " << fraction << std::endl;

    return 0;
}
