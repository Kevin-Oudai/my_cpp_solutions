#include "CharacterCounter.h"

int CharacterCounter::count(const std::string &s, char a) const
{
    if (s.length() == 0)
    {
        return 0;
    }
    return (s[0] == a ? 1 : 0) + count(s.substr(1), a);
}
