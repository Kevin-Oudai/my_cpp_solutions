#ifndef SAMENUMBERSUBSEQUENCE_H
#define SAMENUMBERSUBSEQUENCE_H

#include <vector>

class SameNumberSubsequence
{
public:
    SameNumberSubsequence();
    void find(const std::vector<int>& values);
    int getStartIndex() const;
    int getLength() const;
    int getValue() const;

private:
    int startIndex;
    int length;
    int value;
};

#endif
