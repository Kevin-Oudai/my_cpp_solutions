#include "Person.h"
#include <sstream>

Person::Person()
{
    name = "Unknown";
    address = "Unknown";
    phoneNumber = "Unknown";
    emailAddress = "Unknown";
}

Person::Person(const std::string &name, const std::string &address,
               const std::string &phoneNumber, const std::string &emailAddress)
{
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->emailAddress = emailAddress;
}

Person::~Person()
{
}

std::string Person::getName() const
{
    return name;
}

std::string Person::getAddress() const
{
    return address;
}

std::string Person::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Person::getEmailAddress() const
{
    return emailAddress;
}

std::string Person::toString() const
{
    std::ostringstream output;
    output << "Person: " << name
           << ", address: " << address
           << ", phone: " << phoneNumber
           << ", email: " << emailAddress;
    return output.str();
}
