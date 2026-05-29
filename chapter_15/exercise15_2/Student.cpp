#include "Student.h"
#include <sstream>

Student::Student()
{
    classStatus = "freshman";
}

Student::Student(const std::string &name, const std::string &address,
                 const std::string &phoneNumber, const std::string &emailAddress,
                 const std::string &classStatus)
    : Person(name, address, phoneNumber, emailAddress)
{
    this->classStatus = classStatus;
}

std::string Student::getClassStatus() const
{
    return classStatus;
}

std::string Student::toString() const
{
    std::ostringstream output;
    output << "Student: " << getName()
           << ", status: " << classStatus;
    return output.str();
}
