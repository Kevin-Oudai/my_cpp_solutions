#ifndef SORTEDSTRINGCHECKER_H
#define SORTEDSTRINGCHECKER_H

#include <string>

class SortedStringChecker
{
public:
    SortedStringChecker(const char *filename);
    int run() const;

private:
    const char *filename;

    bool isSorted(bool &fileExists, std::string &first,
                  std::string &second) const;
};

#endif
