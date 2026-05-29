#ifndef STAFF_H
#define STAFF_H

#include "Employee.h"

class Staff : public Employee
{
public:
    Staff();
    Staff(const std::string &name, const std::string &address,
          const std::string &phoneNumber, const std::string &emailAddress,
          const std::string &office, double salary, const MyDate &dateHired,
          const std::string &title);

    std::string getTitle() const;
    virtual std::string toString() const;

private:
    std::string title;
};

#endif
