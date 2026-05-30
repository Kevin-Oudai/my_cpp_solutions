#include "SpaceCounter.h"

int SpaceCounter::numberOfSpaces(const std::string &s) const
{
    return numberOfSpaces(s, 0);
}

int SpaceCounter::numberOfSpaces(const std::string &s, int i) const
{
    if (i >= static_cast<int>(s.length()))
    {
        return 0;
    }
    return (s[i] == ' ' ? 1 : 0) + numberOfSpaces(s, i + 1);
}
