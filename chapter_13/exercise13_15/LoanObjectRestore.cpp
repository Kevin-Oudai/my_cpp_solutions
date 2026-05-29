#include "LoanObjectRestore.h"
#include <fstream>
#include <iostream>

LoanObjectRestore::LoanObjectRestore(const char *filename)
{
    this->filename = filename;
}

int LoanObjectRestore::run() const
{
    double total = 0;
    int count = 0;

    if (!computeTotal(total, count))
    {
        std::cout << filename << " does not exist" << std::endl;
        return 0;
    }

    std::cout << count << " Loan objects are restored" << std::endl;
    std::cout << "Total loan amount is " << total << std::endl;

    return 0;
}

bool LoanObjectRestore::computeTotal(double &total, int &count) const
{
    std::ifstream input(filename, std::ios::binary);

    if (input.fail())
    {
        return false;
    }

    Loan *loan = new Loan;

    input.read((char *)loan, sizeof(Loan));
    while (!input.eof())
    {
        total += loan->getLoanAmount();
        count++;
        input.read((char *)loan, sizeof(Loan));
    }

    delete loan;
    input.close();

    return true;
}
