#include "IncreasingSubstringFinder.h"

std::string IncreasingSubstringFinder::getMaximumConsecutiveSubstring(const std::string& value) const
{
    if (value.length() == 0)
        return "";

    int bestStart = 0;
    int bestLength = 1;
    int currentStart = 0;
    int currentLength = 1;

    for (int i = 1; i < static_cast<int>(value.length()); i++)
    {
        if (value.at(i) > value.at(i - 1))
        {
            currentLength++;
        }
        else
        {
            currentStart = i;
            currentLength = 1;
        }

        if (currentLength > bestLength)
        {
            bestStart = currentStart;
            bestLength = currentLength;
        }
    }

    return value.substr(bestStart, bestLength);
}
