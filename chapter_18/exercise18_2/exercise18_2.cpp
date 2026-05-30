#include <iostream>
#include <string>
#include "IncreasingSubsequenceFinder.h"

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

    IncreasingSubsequenceFinder finder;
    std::cout << "Maximum increasing subsequence is "
        << finder.getMaximumSubsequence(value) << std::endl;
    std::cout << "Time complexity is O(n^2)" << std::endl;

    return 0;
}
