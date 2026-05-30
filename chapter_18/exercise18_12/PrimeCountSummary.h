#ifndef PRIMECOUNTSUMMARY_H
#define PRIMECOUNTSUMMARY_H

#include <string>

class PrimeCountSummary
{
public:
    PrimeCountSummary();
    void displaySummary() const;

private:
    std::string fileName;
    void createSampleFile() const;
    bool fileExistsWithData() const;
};

#endif
