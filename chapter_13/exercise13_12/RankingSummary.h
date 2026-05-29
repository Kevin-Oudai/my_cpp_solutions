#ifndef RANKINGSUMMARY_H
#define RANKINGSUMMARY_H

#include <string>

class RankingSummary
{
public:
    RankingSummary(int rankCount);
    ~RankingSummary();
    int run();

private:
    int rankCount;
    std::string *boyNames;
    std::string *girlNames;

    std::string getFilename(int year) const;
    void displayHeader() const;
    bool readYear(int year);
    void displayYear(int year) const;
};

#endif
