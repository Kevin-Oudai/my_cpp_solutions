#ifndef BOTHGENDERNAMEFINDER_H
#define BOTHGENDERNAMEFINDER_H

#include <string>

class BothGenderNameFinder
{
public:
    BothGenderNameFinder(int capacity);
    ~BothGenderNameFinder();
    int run();

private:
    int capacity;
    int size;
    int bothGenderSize;
    std::string *boyNames;
    std::string *girlNames;
    std::string *bothGenderNames;

    bool readNames(const std::string &filename);
    bool contains(const std::string *list, int size, const std::string &name) const;
    void findBothGenderNames();
    void display() const;
};

#endif
