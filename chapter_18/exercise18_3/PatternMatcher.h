#ifndef PATTERNMATCHER_H
#define PATTERNMATCHER_H

#include <string>

class PatternMatcher
{
public:
    int indexOf(const std::string& text, const std::string& pattern) const;

private:
    void buildPrefixTable(const std::string& pattern, int prefix[]) const;
};

#endif
