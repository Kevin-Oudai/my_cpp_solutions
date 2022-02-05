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

bool isAnagram(const std::string &s1, const std::string &s2)
{
    for (int i = 0; i < s1.length(); i++)
    {
        if (!charIn(s2, s1[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string s1, s2;
    std::cout << "Enter a string s1: ";
    std::cin >> s1;
    std::cout << "Enter a string s2: ";
    std::cin >> s2;
    std::cout << s1 << " and " << s2 << ((isAnagram(s1, s2)) ? " are anagrams." : " are not anagrams.") << std::endl;

    return 0;
}