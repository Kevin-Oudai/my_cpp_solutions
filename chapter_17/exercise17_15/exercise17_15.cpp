#include <iostream>
#include <string>
#include "SpaceCounter.h"

int main()
{
    std::string text;
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    SpaceCounter counter;
    std::cout << "The number of spaces is " << counter.numberOfSpaces(text) << std::endl;

    return 0;
}
