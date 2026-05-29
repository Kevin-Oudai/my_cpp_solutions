#include "LoanObjectStore.h"
#include <fstream>
#include <iostream>

LoanObjectStore::LoanObjectStore(const char *filename, int size)
{
    this->filename = filename;
    this->size = size;
    loans = new Loan[size];
}

LoanObjectStore::~LoanObjectStore()
{
    delete[] loans;
}

int LoanObjectStore::run()
{
    createLoans();
    writeLoans();

    std::cout << size << " Loan objects are stored in "
              << filename << std::endl;
    return 0;
}

void LoanObjectStore::createLoans()
{
    loans[0] = Loan(5.5, 10, 10000);
    loans[1] = Loan(6.0, 15, 25000);
    loans[2] = Loan(6.5, 20, 50000);
    loans[3] = Loan(7.0, 25, 75000);
    loans[4] = Loan(7.5, 30, 100000);
}

void LoanObjectStore::writeLoans() const
{
    std::ofstream output(filename, std::ios::binary);

    for (int i = 0; i < size; i++)
    {
        output.write((char *)&loans[i], sizeof(Loan));
    }

    output.close();
}
