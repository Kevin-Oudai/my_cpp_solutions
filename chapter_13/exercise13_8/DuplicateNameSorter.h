#ifndef DUPLICATENAMESORTER_H
#define DUPLICATENAMESORTER_H

#include <string>

class DuplicateNameSorter
{
public:
    DuplicateNameSorter(int capacity, const char *outputFilename);
    ~DuplicateNameSorter();
    int run();

private:
    int capacity;
    int size;
    std::string *names;
    const char *outputFilename;

    std::string getFilename(int year) const;
    void addName(const std::string &name);
    bool readNames();
    void sortNames();
    void writeNames() const;
};

#endif
