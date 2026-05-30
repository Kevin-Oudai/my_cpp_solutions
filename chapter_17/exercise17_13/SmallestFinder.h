#ifndef SMALLESTFINDER_H
#define SMALLESTFINDER_H

#include <vector>

class SmallestFinder
{
public:
    int smallest(const std::vector<int> &values) const;

private:
    int smallest(const std::vector<int> &values, int high) const;
};

#endif
