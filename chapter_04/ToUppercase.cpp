// Listing 4.2 - ToUppercase.cpp

#include <iostream>

int main()
{
    std::cout << "Enter a lowercase letter: ";
    char lowercaseLetter;
    std::cin >> lowercaseLetter;
    char uppercaseLetter = static_cast<char>('A' + (lowercaseLetter - 'a'));

    std::cout << "The corresponding uppercase letter is " << uppercaseLetter << std::endl;

    return 0;
}