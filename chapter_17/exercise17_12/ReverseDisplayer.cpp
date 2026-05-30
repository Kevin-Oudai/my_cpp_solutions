#include "ReverseDisplayer.h"
#include <iostream>

void ReverseDisplayer::reverseDisplay(const std::string &s) const
{
    reverseDisplay(s, static_cast<int>(s.length()) - 1);
}

void ReverseDisplayer::reverseDisplay(const std::string &s, int high) const
{
    if (high < 0)
    {
        return;
    }
    std::cout << s[high];
    reverseDisplay(s, high - 1);
}
