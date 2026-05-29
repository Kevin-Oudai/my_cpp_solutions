#ifndef LOANOBJECTRESTORE_H
#define LOANOBJECTRESTORE_H

#include "Loan.h"

class LoanObjectRestore
{
public:
    LoanObjectRestore(const char *filename);
    int run() const;

private:
    const char *filename;

    bool computeTotal(double &total, int &count) const;
};

#endif
