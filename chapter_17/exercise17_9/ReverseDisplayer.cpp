#include "ReverseDisplayer.h"
#include <iostream>

void ReverseDisplayer::reverseDisplay(const std::string &s) const
{
    if (s.length() == 0)
    {
        return;
    }
    std::cout << s[s.length() - 1];
    reverseDisplay(s.substr(0, s.length() - 1));
}
