#ifndef CUMULATIVERANKING_H
#define CUMULATIVERANKING_H

#include <string>

class CumulativeRanking
{
public:
    CumulativeRanking(int capacity);
    ~CumulativeRanking();
    int run();

private:
    int capacity;
    int boySize;
    int girlSize;
    std::string *boyNames;
    std::string *girlNames;
    int *boyCounts;
    int *girlCounts;

    std::string getFilename(int year) const;
    int parseCount(const std::string &text) const;
    int findName(const std::string *names, int size, const std::string &name) const;
    void addName(std::string *names, int *counts, int &size,
                 const std::string &name, int count);
    bool readFiles();
    void sortByCount(std::string *names, int *counts, int size);
    void displayRanking(const char *title, const std::string *names,
                        const int *counts, int size) const;
};

#endif
