#ifndef PRIMEFILEBUILDER_H
#define PRIMEFILEBUILDER_H

#include <string>

class PrimeFileBuilder
{
public:
    PrimeFileBuilder();
    void generateThrough(long limit);
    long countPrimes() const;
    long getLastPrime() const;

private:
    std::string fileName;
    void ensureSeedFile() const;
    bool isPrimeFromFile(long number) const;
    void appendPrime(long number) const;
};

#endif
