#include "PatternMatcher.h"

void PatternMatcher::buildPrefixTable(const std::string& pattern, int prefix[]) const
{
    int length = 0;
    prefix[0] = 0;

    int i = 1;
    while (i < static_cast<int>(pattern.length()))
    {
        if (pattern.at(i) == pattern.at(length))
        {
            length++;
            prefix[i] = length;
            i++;
        }
        else if (length != 0)
        {
            length = prefix[length - 1];
        }
        else
        {
            prefix[i] = 0;
            i++;
        }
    }
}

int PatternMatcher::indexOf(const std::string& text, const std::string& pattern) const
{
    if (pattern.length() == 0)
        return 0;
    if (text.length() < pattern.length())
        return -1;

    int* prefix = new int[pattern.length()];
    buildPrefixTable(pattern, prefix);

    int i = 0;
    int j = 0;
    while (i < static_cast<int>(text.length()))
    {
        if (text.at(i) == pattern.at(j))
        {
            i++;
            j++;

            if (j == static_cast<int>(pattern.length()))
            {
                int result = i - j;
                delete [] prefix;
                return result;
            }
        }
        else if (j != 0)
        {
            j = prefix[j - 1];
        }
        else
        {
            i++;
        }
    }

    delete [] prefix;
    return -1;
}
