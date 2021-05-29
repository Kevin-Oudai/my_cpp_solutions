// Exercise 4.11 - Convert an uppercase letter to lowercase

#include <iostream>

int main()
{
    std::cout << "Enter an uppercase letter: ";
    char uppercaseLetter;
    std::cin >> uppercaseLetter;

    char lowercaseLetter = static_cast<char>('a' + (uppercaseLetter - 'A'));
    std::cout << "The lowercase letter is " << lowercaseLetter << std::endl;
    return 0;
}