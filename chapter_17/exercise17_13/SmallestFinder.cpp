#include "SmallestFinder.h"

int SmallestFinder::smallest(const std::vector<int> &values) const
{
    return smallest(values, static_cast<int>(values.size()) - 1);
}

int SmallestFinder::smallest(const std::vector<int> &values, int high) const
{
    if (high == 0)
    {
        return values[0];
    }

    int currentSmallest = smallest(values, high - 1);
    return values[high] < currentSmallest ? values[high] : currentSmallest;
}
