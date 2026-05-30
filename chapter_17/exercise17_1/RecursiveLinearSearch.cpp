#include "RecursiveLinearSearch.h"

int RecursiveLinearSearch::search(const std::vector<int> &values, int key) const
{
    return search(values, key, 0);
}

int RecursiveLinearSearch::search(const std::vector<int> &values, int key, int index) const
{
    if (index >= static_cast<int>(values.size()))
    {
        return -1;
    }
    if (values[index] == key)
    {
        return index;
    }
    return search(values, key, index + 1);
}
