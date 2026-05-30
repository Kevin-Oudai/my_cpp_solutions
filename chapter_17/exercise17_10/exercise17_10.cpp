#include <iostream>
#include <string>
#include "CharacterCounter.h"

int main()
{
    std::string text;
    char ch;

    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    std::cout << "Enter a character: ";
    std::cin >> ch;

    CharacterCounter counter;
    std::cout << "The character " << ch << " appears "
              << counter.count(text, ch) << " time(s)" << std::endl;

    return 0;
}
