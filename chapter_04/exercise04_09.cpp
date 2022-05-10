// Exercise 4.9 - Find the ASCII code of a character

#include <iostream>

int main()
{

    std::cout << "Enter a character: ";
    char code;
    std::cin >> code;

    // Get a random character
    int asciiCharacter = static_cast<int>(code);
    std::cout << "The ASCII code for the character is " << asciiCharacter << std::endl;

    return 0;
}