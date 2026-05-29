#ifndef FACULTY_H
#define FACULTY_H

#include "Employee.h"

class Faculty : public Employee
{
public:
    Faculty();
    Faculty(const std::string &name, const std::string &address,
            const std::string &phoneNumber, const std::string &emailAddress,
            const std::string &office, double salary, const MyDate &dateHired,
            const std::string &officeHours, const std::string &rank);

    std::string getOfficeHours() const;
    std::string getRank() const;
    virtual std::string toString() const;

private:
    std::string officeHours;
    std::string rank;
};

#endif
