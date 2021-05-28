#include <iostream>

int main()
{
    std::cout << "Enter a letter: ";
    char character;
    std::cin >> character;
    int characterCode = static_cast<int>(character);
    std::cout << "Character Code: " << characterCode << std::endl;

    if (character == 'A' || character == 'a' ||
        character == 'E' || character == 'e' ||
        character == 'I' || character == 'i' ||
        character == 'O' || character == 'o' ||
        character == 'U' || character == 'u')
    {
        std::cout << character << " is a vowel" << std::endl;
    }
    else if ((characterCode >= 65 && characterCode <= 90) || (characterCode >= 97 && characterCode <= 122))
    {
        std::cout << character << " is a consonant" << std::endl;
    }
    else
    {
        std::cout << character << " is an invalid input" << std::endl;
    }
    return 0;
}