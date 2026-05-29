#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
    Person();
    Person(const std::string &name, const std::string &address,
           const std::string &phoneNumber, const std::string &emailAddress);
    virtual ~Person();

    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    std::string getEmailAddress() const;

    virtual std::string toString() const;

private:
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string emailAddress;
};

#endif
