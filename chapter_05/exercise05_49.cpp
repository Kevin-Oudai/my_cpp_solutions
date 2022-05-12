// Exercise 5.49 - Longest Common Prefix

#include <iostream>
#include <string>

int main()
{
    std::string s1, s2, common;
    std::cout << "Enter s1: ";
    std::getline(std::cin, s1);

    std::cout << "Enter s2: ";
    std::getline(std::cin, s2);

    int s1Length = s1.length(), s2Length = s2.length();
    int count = (s1Length >= s2Length) ? s2Length : s1Length;
    for (int i = 0; i < count; i++)
    {
        if (s1.at(i) == s2.at(i))
        {
            common += s1.at(i);
        }
        else
        {
            break;
        }
    }

    if (common.length() > 0)
    {
        std::cout << "The common prefix is " << common << std::endl;
    }
    else
    {
        std::cout << s1 << " and " << s2 << " have no common prefix.\n";
    }
    return 0;
}