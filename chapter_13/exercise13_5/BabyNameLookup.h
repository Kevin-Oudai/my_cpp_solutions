#ifndef BABYNAMELOOKUP_H
#define BABYNAMELOOKUP_H

#include <string>

class BabyNameLookup
{
public:
    int run() const;

private:
    std::string getFilename(int year) const;
    int findRank(const std::string &filename, char gender,
                 const std::string &name, bool &fileExists) const;
};

#endif
