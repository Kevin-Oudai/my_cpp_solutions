#include <iostream>
#include <string>
#include "IncreasingSubstringFinder.h"

void removeCarriageReturn(std::string& value)
{
    if (value.length() > 0 && value.at(value.length() - 1) == '\r')
        value.erase(value.length() - 1, 1);
}

int main()
{
    std::cout << "Enter a string: ";
    std::string value;
    std::getline(std::cin, value);
    removeCarriageReturn(value);

    IncreasingSubstringFinder finder;
    std::cout << "Maximum consecutive substring is "
        << finder.getMaximumConsecutiveSubstring(value) << std::endl;
    std::cout << "Time complexity is O(n)" << std::endl;

    return 0;
}
