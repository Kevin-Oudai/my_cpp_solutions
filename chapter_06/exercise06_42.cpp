// Exercise 6.42 - Display Longest String

#include <iostream>
#include <string>

std::string longest(const std::string &s1, const std::string &s2)
{
    if (s1.length() > s2.length())
        return s1;
    return s2;
}

int main()
{
    std::cout << "Enter the first string: ";
    std::string s1, s2;
    std::getline(std::cin, s1);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, s2);

    std::cout << "The longest string is: " << longest(s1, s2) << std::endl;
    return 0;
}