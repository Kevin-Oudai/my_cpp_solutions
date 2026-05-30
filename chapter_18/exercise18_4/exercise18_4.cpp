#include <iostream>
#include <string>
#include "GeneralPatternMatcher.h"

void removeCarriageReturn(std::string& value)
{
    if (value.length() > 0 && value.at(value.length() - 1) == '\r')
        value.erase(value.length() - 1, 1);
}

int main()
{
    std::cout << "Enter a string s1: ";
    std::string text;
    std::getline(std::cin, text);
    removeCarriageReturn(text);

    std::cout << "Enter a string s2: ";
    std::string pattern;
    std::getline(std::cin, pattern);
    removeCarriageReturn(pattern);

    GeneralPatternMatcher matcher;
    int index = matcher.indexOf(text, pattern);

    if (index >= 0)
        std::cout << "matched at index " << index << std::endl;
    else
        std::cout << "unmatched" << std::endl;

    return 0;
}
