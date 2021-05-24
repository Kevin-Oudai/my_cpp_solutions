// Listing 4.3 - DisplayRandomCharacter.cpp

#include <iostream>
#include <cstdlib>

int main()
{
    std::cout << "Enter a starting character: ";
    char startChar;
    std::cin >> startChar;

    std::cout << "Enter an ending character: ";
    char endChar;
    std::cin >> endChar;

    // Get a random character
    char randomChar = static_cast<char>(startChar + rand() % (endChar - startChar + 1));
    std::cout << "The random character between " << startChar << " and "
              << endChar << " is " << randomChar << std::endl;

    return 0;
}