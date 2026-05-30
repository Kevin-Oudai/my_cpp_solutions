#ifndef PRIMEPERFORMANCE_H
#define PRIMEPERFORMANCE_H

class PrimePerformance
{
public:
    void displayTable(bool useExerciseLimits) const;

private:
    int countBySquareRoot(int limit) const;
    int countByPrimeVector(int limit) const;
    int countBySieve(int limit) const;
    long timeAlgorithm(int algorithm, int limit, int& count) const;
};

#endif
