#include "PermutationDisplayer.h"
#include <iostream>

void PermutationDisplayer::displayPermutation(const std::string &s) const
{
    displayPermutation("", s);
}

void PermutationDisplayer::displayPermutation(const std::string &s1, const std::string &s2) const
{
    if (s2.length() == 0)
    {
        std::cout << s1 << std::endl;
    }
    else
    {
        for (int i = 0; i < static_cast<int>(s2.length()); i++)
        {
            std::string nextS1 = s1 + s2[i];
            std::string nextS2 = s2.substr(0, i) + s2.substr(i + 1);
            displayPermutation(nextS1, nextS2);
        }
    }
}
