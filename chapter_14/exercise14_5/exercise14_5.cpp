#include <iostream>
#include "MyString.h"

void printBoolean(bool value)
{
    std::cout << (value ? "true" : "false");
}

int main()
{
    MyString first;
    MyString second;

    std::cout << "Enter first string: ";
    std::cin >> first;

    std::cout << "Enter second string: ";
    std::cin >> second;

    std::cout << first << " == " << second << ": ";
    printBoolean(first == second);
    std::cout << std::endl;

    std::cout << first << " != " << second << ": ";
    printBoolean(first != second);
    std::cout << std::endl;

    std::cout << first << " > " << second << ": ";
    printBoolean(first > second);
    std::cout << std::endl;

    std::cout << first << " >= " << second << ": ";
    printBoolean(first >= second);
    std::cout << std::endl;

    return 0;
}
