#include "IncreasingSubsequenceFinder.h"
#include <vector>

std::string IncreasingSubsequenceFinder::getMaximumSubsequence(const std::string& value) const
{
    int size = static_cast<int>(value.length());
    if (size == 0)
        return "";

    std::vector<int> lengths(size);
    std::vector<int> previous(size);

    for (int i = 0; i < size; i++)
    {
        lengths[i] = 1;
        previous[i] = -1;
    }

    int bestIndex = 0;
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (value.at(i) > value.at(j) && lengths[j] + 1 > lengths[i])
            {
                lengths[i] = lengths[j] + 1;
                previous[i] = j;
            }
        }

        if (lengths[i] > lengths[bestIndex])
            bestIndex = i;
    }

    std::string reversed;
    int current = bestIndex;
    while (current != -1)
    {
        reversed += value.at(current);
        current = previous[current];
    }

    std::string result;
    for (int i = static_cast<int>(reversed.length()) - 1; i >= 0; i--)
        result += reversed.at(i);

    return result;
}
