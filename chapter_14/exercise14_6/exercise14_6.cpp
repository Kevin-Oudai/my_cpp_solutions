#include <iostream>
#include "MyString.h"

int main()
{
    MyString first("Hello");
    MyString second("World");

    std::cout << "First string: " << first << std::endl;
    std::cout << "Second string: " << second << std::endl;
    std::cout << "first[1]: " << first[1] << std::endl;

    MyString combined = first + MyString(" ") + second;
    std::cout << "Using +: " << combined << std::endl;

    first += MyString(" ");
    first += second;
    std::cout << "Using +=: " << first << std::endl;

    first[0] = 'h';
    std::cout << "After changing first[0]: " << first << std::endl;

    return 0;
}
