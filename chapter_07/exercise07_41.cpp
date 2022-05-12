// Exercise 7.41 - Decimal to Octal to Hex

#include <iostream>
#include <cstring>

void itoaUse(int value, char s[], int radix)
{
    itoa(value, s, radix);
}

int main()
{
    std::cout << "Enter an integer: ";
    int value;
    std::cin >> value;

    char s[100] = {};
    std::cout << "Enter the radix: ";
    int radix;
    std::cin >> radix;

    itoaUse(value, s, radix);

    if (radix == 8)
    {
        std::cout << "The octal equivalent is: " << s << std::endl;
    }
    else if (radix == 16)
    {
        std::cout << "The Hexagonal equivalent is: " << s << std::endl;
    }
    else
    {
        std::cout << "Your input is invalid." << std::endl;
    }
    return 0;
}