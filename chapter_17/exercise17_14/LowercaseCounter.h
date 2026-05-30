#ifndef LOWERCASECOUNTER_H
#define LOWERCASECOUNTER_H

#include <string>

class LowercaseCounter
{
public:
    int getNumberOfLowercaseLetters(const std::string &s) const;
    int getNumberOfLowercaseLetters(const std::string &s, int low) const;
};

#endif
