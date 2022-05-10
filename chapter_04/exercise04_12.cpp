// Exercise 4.12 - Convert letter grade to number

#include <iostream>

int main()
{
    int characterValue, characterCode;

    std::cout << "Enter a letter grade: ";
    char character;
    std::cin >> character;
    int value;

    if (character == 'A' || character == 'a')
    {
        std::cout << "The numeric value for grade " << character << " is " << 4 << std::endl;
    }
    else if (character == 'B' || character == 'b')
    {
        std::cout << "The numeric value for grade " << character << " is " << 3 << std::endl;
    }
    else if (character == 'C' || character == 'c')
    {
        std::cout << "The numeric value for grade " << character << " is " << 2 << std::endl;
    }
    else if (character == 'D' || character == 'd')
    {
        std::cout << "The numeric value for grade " << character << " is " << 1 << std::endl;
    }
    else if (character == 'F' || character == 'f')
    {
        std::cout << "The numeric value for grade " << character << " is " << 0 << std::endl;
    }
    else
    {
        std::cout << character << " is an invalid grade" << std::endl;
    }

    return 0;
}