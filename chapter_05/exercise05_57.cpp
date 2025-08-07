// Exercise 5.57 - Check Student ID

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a student ID: ";
    std::string message;
    std::getline(std::cin, message);

    bool isCorrectLength = (message.length() == 10) ? true : false;
    bool isAlphaNumeric = true;
    for (int i = 0; i < message.length(); i++)
    {
        if (!(isalnum(message.at(i))))
        {
            isAlphaNumeric = false;
            break;
        }
    }
    bool startsWithDigit = (isdigit(message.at(0))) ? true : false;
    (isCorrectLength && isAlphaNumeric && startsWithDigit) ? std::cout << "Valid Student ID\n" : std::cout << "Invalid Student ID\n";

    return 0;
}