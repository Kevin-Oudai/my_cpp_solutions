#include <iostream>
#include <string>

int main()
{
    std::string ssn;
    std::cout << "Enter a SSN: ";
    std::getline(std::cin, ssn);

    bool allDigits = ((static_cast<int>(ssn[0]) >= 48 && static_cast<int>(ssn[0]) <= 57) &&
                      (static_cast<int>(ssn[1]) >= 48 && static_cast<int>(ssn[1]) <= 57) &&
                      (static_cast<int>(ssn[2]) >= 48 && static_cast<int>(ssn[2]) <= 57) &&
                      (static_cast<int>(ssn[4]) >= 48 && static_cast<int>(ssn[4]) <= 57) &&
                      (static_cast<int>(ssn[5]) >= 48 && static_cast<int>(ssn[5]) <= 57) &&
                      (static_cast<int>(ssn[7]) >= 48 && static_cast<int>(ssn[7]) <= 57) &&
                      (static_cast<int>(ssn[8]) >= 48 && static_cast<int>(ssn[8]) <= 57) &&
                      (static_cast<int>(ssn[9]) >= 48 && static_cast<int>(ssn[9]) <= 57) &&
                      (static_cast<int>(ssn[10]) >= 48 && static_cast<int>(ssn[10]) <= 57));
    if (ssn[3] == '-' && ssn[6] == '-' && allDigits)
    {
        std::cout << ssn << " is a valid social security number" << std::endl;
    }
    else
        std::cout << ssn << " is an invalid social security number" << std::endl;
    return 0;
}