// Exercise 7.40 - Decimal to Binary

#include <iostream>
#include <cstring>

void itoaUse(int value, char s[], int radix)
{
    itoa(value, s, radix);
}

int main()
{
    std::cout << "Enter an integer: ";
    char s[100] = {};
    int value;
    std::cin >> value;

    int radix = 2;
    itoaUse(value, s, radix);
    std::cout << "The binary equivalent is: ";
    for (int i = 0; i < strlen(s); i++)
    {
        std::cout << s[i];
    }
    std::cout << std::endl;
    return 0;
}