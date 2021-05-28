// Exercise 4.8 - Find the character of an ASCII code

#include <iostream>

int main()
{

    std::cout << "Enter an ASCII code: ";
    int code;
    std::cin >> code;

    // Get a random character
    char asciiCharacter = static_cast<char>(code);
    std::cout << "The character is " << asciiCharacter << std::endl;

    return 0;
}