// Listing 4.5 - CharacterFunctions.cpp

#include <iostream>
#include <cctype>

int main()
{
    std::cout << "Enter a character: ";
    char ch;
    std::cin >> ch;

    std::cout << "You entered " << ch << std::endl;

    if (islower(ch))
    {
        std::cout << "It is a lowercase letter " << std::endl;
        std::cout << "Its equivalent upercase letter is "
                  << static_cast<char>(toupper(ch)) << std::endl;
    }
    else if (isupper(ch))
    {
        std::cout << "It is an uppercase letter " << std::endl;
        std::cout << "Its equivalent lowercase letter is "
                  << static_cast<char>(tolower(ch)) << std::endl;
    }
    else if (isdigit(ch))
    {
        std::cout << "It is a digit character " << std::endl;
    }

    return 0;
}