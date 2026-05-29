#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{
public:
    Student();
    Student(const std::string &name, const std::string &address,
            const std::string &phoneNumber, const std::string &emailAddress,
            const std::string &classStatus);

    std::string getClassStatus() const;
    virtual std::string toString() const;

private:
    std::string classStatus;
};

#endif
