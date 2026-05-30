#include "SameNumberSubsequence.h"

SameNumberSubsequence::SameNumberSubsequence()
{
    startIndex = 0;
    length = 0;
    value = 0;
}

void SameNumberSubsequence::find(const std::vector<int>& values)
{
    if (values.size() == 0)
    {
        startIndex = 0;
        length = 0;
        value = 0;
        return;
    }

    int currentStart = 1;
    int currentLength = 1;
    startIndex = 1;
    length = 1;
    value = values[0];

    for (int i = 1; i < static_cast<int>(values.size()); i++)
    {
        if (values[i] == values[i - 1])
        {
            currentLength++;
        }
        else
        {
            currentStart = i + 1;
            currentLength = 1;
        }

        if (currentLength > length)
        {
            startIndex = currentStart;
            length = currentLength;
            value = values[i];
        }
    }
}

int SameNumberSubsequence::getStartIndex() const
{
    return startIndex;
}

int SameNumberSubsequence::getLength() const
{
    return length;
}

int SameNumberSubsequence::getValue() const
{
    return value;
}
