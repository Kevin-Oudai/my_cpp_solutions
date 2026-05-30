#ifndef LASTPRIMEREADER_H
#define LASTPRIMEREADER_H

#include <vector>
#include <string>

class LastPrimeReader
{
public:
    LastPrimeReader();
    std::vector<long> readLastPrimes(int count);

private:
    std::string fileName;
    void createSampleFile() const;
    bool fileExistsWithData() const;
};

#endif
