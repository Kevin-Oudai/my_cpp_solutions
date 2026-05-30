#include "GeneralPatternMatcher.h"

int GeneralPatternMatcher::indexOf(const std::string& text, const std::string& pattern) const
{
    if (pattern.length() == 0)
        return 0;
    if (text.length() < pattern.length())
        return -1;

    int lastStart = static_cast<int>(text.length() - pattern.length());
    for (int i = 0; i <= lastStart; i++)
    {
        int k = 0;
        while (k < static_cast<int>(pattern.length()) && text.at(i + k) == pattern.at(k))
            k++;

        if (k == static_cast<int>(pattern.length()))
            return i;
    }

    return -1;
}
