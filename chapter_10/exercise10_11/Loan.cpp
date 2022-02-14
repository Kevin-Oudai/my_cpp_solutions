// Listing 9.15 - Loan.cpp
#include "Loan.h"
#include <cmath>

Loan::Loan()
{
    annualInterestRate = 9.5;
    numberOfYears = 30;
    loanAmount = 100000;
}

Loan::Loan(double rate, int years, double amount)
{
    annualInterestRate = rate;
    numberOfYears = years;
    loanAmount = amount;
}

double Loan::getAnnualInterestRate()
{
    return annualInterestRate;
}

int Loan::getNumberOfYears()
{
    return numberOfYears;
}

double Loan::getLoanAmount()
{
    return loanAmount;
}

void Loan::setAnnualInterestRate(double rate)
{
    annualInterestRate = rate;
}

void Loan::setNumberOfYears(int years)
{
    numberOfYears = years;
}

void Loan::setLoanAmount(double amount)
{
    loanAmount = amount;
}

double Loan::getMonthlyPayment()
{
    double monthlyInterestRate = annualInterestRate / 1200;
    return loanAmount * monthlyInterestRate / (1 - (pow(1 / (1 + monthlyInterestRate), numberOfYears * 12)));
}

double Loan::getTotalPayment()
{
    return getMonthlyPayment() * numberOfYears * 12;
}

double Loan::getMonthlyPayment(double annualInterestRate, int numberOfYears, double loanAmount)
{
    double monthlyInterestRate = annualInterestRate / 1200;
    return loanAmount * monthlyInterestRate / (1 - (pow(1 / (1 + monthlyInterestRate), numberOfYears * 12)));
}

double Loan::getTotalPayment(double annualInterestRate, int numberOfYears, double loanAmount)
{
    return getMonthlyPayment(annualInterestRate, numberOfYears, loanAmount) * numberOfYears * 12;
}