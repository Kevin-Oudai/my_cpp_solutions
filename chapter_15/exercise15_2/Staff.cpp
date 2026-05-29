#include "Staff.h"
#include <sstream>

Staff::Staff()
{
    title = "Unknown";
}

Staff::Staff(const std::string &name, const std::string &address,
             const std::string &phoneNumber, const std::string &emailAddress,
             const std::string &office, double salary, const MyDate &dateHired,
             const std::string &title)
    : Employee(name, address, phoneNumber, emailAddress, office, salary, dateHired)
{
    this->title = title;
}

std::string Staff::getTitle() const
{
    return title;
}

std::string Staff::toString() const
{
    std::ostringstream output;
    output << "Staff: " << getName()
           << ", title: " << title;
    return output.str();
}
