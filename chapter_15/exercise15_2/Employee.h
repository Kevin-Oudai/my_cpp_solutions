#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "MyDate.h"
#include "Person.h"

class Employee : public Person
{
public:
    Employee();
    Employee(const std::string &name, const std::string &address,
             const std::string &phoneNumber, const std::string &emailAddress,
             const std::string &office, double salary, const MyDate &dateHired);

    std::string getOffice() const;
    double getSalary() const;
    MyDate getDateHired() const;
    virtual std::string toString() const;

private:
    std::string office;
    double salary;
    MyDate dateHired;
};

#endif
