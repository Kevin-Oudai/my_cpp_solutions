// Exercise 6.43 - Check Substring

#include <iostream>
#include <string>

bool substringExists(const std::string &s1, const std::string &s2, int i, int s1Length)
{
    bool exists = true;
    for (int j = 0; j < s1Length; j++)
    {
        if (s1.at(j) != s2.at(i + j))
        {
            exists = false;
        }
    }
    return exists;
}
int indexOf(const std::string &s1, const std::string &s2)
{
    int s1Length = s1.length(), s2Length = s2.length();
    for (int i = 0; i < s2Length; i++)
    {
        if ((s1.at(0) == s2.at(i)) && substringExists(s1, s2, i, s1Length))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::cout << "Enter the first string: ";
    std::string s1, s2;
    std::getline(std::cin, s1);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, s2);

    int index = indexOf(s1, s2);
    std::cout << "indexOf( \"" << s1 << ", "
              << "\"" << s2 << "\") is " << index << std::endl;

    return 0;
}