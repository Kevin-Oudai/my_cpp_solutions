#include "Faculty.h"
#include <sstream>

Faculty::Faculty()
{
    officeHours = "Unknown";
    rank = "Unknown";
}

Faculty::Faculty(const std::string &name, const std::string &address,
                 const std::string &phoneNumber, const std::string &emailAddress,
                 const std::string &office, double salary, const MyDate &dateHired,
                 const std::string &officeHours, const std::string &rank)
    : Employee(name, address, phoneNumber, emailAddress, office, salary, dateHired)
{
    this->officeHours = officeHours;
    this->rank = rank;
}

std::string Faculty::getOfficeHours() const
{
    return officeHours;
}

std::string Faculty::getRank() const
{
    return rank;
}

std::string Faculty::toString() const
{
    std::ostringstream output;
    output << "Faculty: " << getName()
           << ", office hours: " << officeHours
           << ", rank: " << rank;
    return output.str();
}
