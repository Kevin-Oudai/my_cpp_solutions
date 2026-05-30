#include <iostream>
#include <string>
#include "LowercaseCounter.h"

int main()
{
    std::string text;
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    LowercaseCounter counter;
    std::cout << "The number of lowercase letters is "
              << counter.getNumberOfLowercaseLetters(text) << std::endl;

    return 0;
}
