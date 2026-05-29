#ifndef UNIQUENAMESORTER_H
#define UNIQUENAMESORTER_H

#include <string>

class UniqueNameSorter
{
public:
    UniqueNameSorter(int capacity, const char *outputFilename);
    ~UniqueNameSorter();
    int run();

private:
    int capacity;
    int size;
    std::string *names;
    const char *outputFilename;

    std::string getFilename(int year) const;
    bool contains(const std::string &name) const;
    void addName(const std::string &name);
    bool readNames();
    void sortNames();
    void writeNames() const;
};

#endif
