// Exercise 4.16 -  Process two string

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter the first string: ";
    std::string firstString;
    std::getline(std::cin, firstString);

    std::cout << "Enter the second string: ";
    std::string secondString;
    std::getline(std::cin, secondString);

    std::cout << "The length of the first string is: " << firstString.length() << " characters."
              << "\n The last character is " << firstString[firstString.length() - 1] << std::endl;

    std::cout << "The length of the second string is: " << secondString.length() << " characters."
              << "\n The last character is " << secondString[secondString.length() - 1] << std::endl;

    return 0;
}