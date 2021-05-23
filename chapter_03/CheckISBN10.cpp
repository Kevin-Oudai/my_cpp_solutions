#include <iostream>

int main()
{
    int digits;
    std::cout << "Enter the first 9 digits of an ISBN as integer: ";
    std::cin >> digits;

    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;

    d9 = digits % 10;
    digits /= 10;

    d8 = digits % 10;
    digits /= 10;

    d7 = digits % 10;
    digits /= 10;

    d6 = digits % 10;
    digits /= 10;

    d5 = digits % 10;
    digits /= 10;

    d4 = digits % 10;
    digits /= 10;

    d3 = digits % 10;
    digits /= 10;

    d2 = digits % 10;
    digits /= 10;

    d1 = digits % 10;
    digits /= 10;

    d10 = (d1 * 1 + d2 * 2 + d3 * 3 + d4 * 4 + d5 * 5 + d6 * 6 + d7 * 7 + d8 * 8 + d9 * 9) % 11;

    if (d10 == 10)
    {
        std::cout << "The ISBN-10 number is " << d1 << d2 << d3 << d4 << d5
                  << d6 << d7 << d8 << d9 << "X" << std::endl;
    }
    else
    {
        std::cout << "The ISBN-10 number is " << d1 << d2 << d3 << d4 << d5
                  << d6 << d7 << d8 << d9 << d10 << std::endl;
    }

    return 0;
}