#ifndef RECURSIVELINEARSEARCH_H
#define RECURSIVELINEARSEARCH_H

#include <vector>

class RecursiveLinearSearch
{
public:
    int search(const std::vector<int> &values, int key) const;

private:
    int search(const std::vector<int> &values, int key, int index) const;
};

#endif
