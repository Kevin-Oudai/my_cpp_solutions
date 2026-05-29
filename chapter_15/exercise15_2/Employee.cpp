#include "Employee.h"
#include <sstream>

Employee::Employee()
{
    office = "Unknown";
    salary = 0;
    dateHired = MyDate();
}

Employee::Employee(const std::string &name, const std::string &address,
                   const std::string &phoneNumber, const std::string &emailAddress,
                   const std::string &office, double salary, const MyDate &dateHired)
    : Person(name, address, phoneNumber, emailAddress)
{
    this->office = office;
    this->salary = salary;
    this->dateHired = dateHired;
}

std::string Employee::getOffice() const
{
    return office;
}

double Employee::getSalary() const
{
    return salary;
}

MyDate Employee::getDateHired() const
{
    return dateHired;
}

std::string Employee::toString() const
{
    std::ostringstream output;
    output << "Employee: " << getName()
           << ", office: " << office
           << ", salary: " << salary
           << ", date hired: " << dateHired.toString();
    return output.str();
}
