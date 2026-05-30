#include "LowercaseCounter.h"

int LowercaseCounter::getNumberOfLowercaseLetters(const std::string &s) const
{
    return getNumberOfLowercaseLetters(s, 0);
}

int LowercaseCounter::getNumberOfLowercaseLetters(const std::string &s, int low) const
{
    if (low >= static_cast<int>(s.length()))
    {
        return 0;
    }

    int count = (s[low] >= 'a' && s[low] <= 'z') ? 1 : 0;
    return count + getNumberOfLowercaseLetters(s, low + 1);
}
