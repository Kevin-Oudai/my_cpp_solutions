#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter two characters: ";
    std::string status, statement;
    std::getline(std::cin, status);

    if (status[0] == 'M')
    {
        statement = "Mathematics";
    }
    else if (status[0] == 'C')
    {
        statement = "Computer Science";
    }
    else if (status[0] == 'I')
    {
        statement = "Information Technology";
    }
    else
    {
        statement = "Invalid major code";
    }

    if (statement == "Invalid major code")
    {
        std::cout << statement << std::endl;
    }
    else if (status[1] == '1')
    {
        statement += " Freshman";
    }
    else if (status[1] == '2')
    {
        statement += " Sophomore";
    }
    else if (status[1] == '3')
    {
        statement += " Junior";
    }
    else if (status[1] == '4')
    {
        statement += " Senior";
    }
    else
    {
        statement = "Invalid Status Code";
    }

    if (statement != "Invalid major code")
        std::cout << statement << std::endl;
    return 0;
}