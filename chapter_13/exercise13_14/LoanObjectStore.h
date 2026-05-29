#ifndef LOANOBJECTSTORE_H
#define LOANOBJECTSTORE_H

#include "Loan.h"

class LoanObjectStore
{
public:
    LoanObjectStore(const char *filename, int size);
    ~LoanObjectStore();
    int run();

private:
    const char *filename;
    int size;
    Loan *loans;

    void createLoans();
    void writeLoans() const;
};

#endif
