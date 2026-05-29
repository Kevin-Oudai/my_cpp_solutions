#ifndef LOAN_H
#define LOAN_H

class Loan
{
public:
    Loan();
    Loan(double rate, int years, double amount);
    double getAnnualInterestRate();
    int getNumberOfYears();
    double getLoanAmount();
    void setAnnualInterestRate(double rate);
    void setNumberOfYears(int years);
    void setLoanAmount(double amount);
    double getMonthlyPayment();
    double getTotalPayment();

private:
    double annualInterestRate;
    int numberOfYears;
    double loanAmount;
};

#endif
