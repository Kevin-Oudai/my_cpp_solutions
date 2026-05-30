#ifndef SPACECOUNTER_H
#define SPACECOUNTER_H

#include <string>

class SpaceCounter
{
public:
    int numberOfSpaces(const std::string &s) const;
    int numberOfSpaces(const std::string &s, int i) const;
};

#endif
