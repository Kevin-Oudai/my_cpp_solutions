#include <iostream>
#include <string>

bool charIn(const std::string &s, char ch)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (ch == s[i])
        {
            return true;
        }
    }
    return false;
}

std::string commonChars(const std::string &s1, const std::string &s2)
{
    std::string common;
    for (int i = 0; i < s1.length(); i++)
    {
        if (charIn(s2, s1[i]))
        {
            common.append(s1, i, 1);
        }
    }
    return common;
}

int main()
{
    std::string s1, s2;
    std::cout << "Enter a string s1: ";
    std::cin >> s1;
    std::cout << "Enter a string s2: ";
    std::cin >> s2;
    std::string common = commonChars(s1, s2);
    if (common.length() > 0)
    {
        std::cout << "The common characters are " << common << std::endl;
    }
    else
    {
        std::cout << "No common characters." << std::endl;
    }

    return 0;
}