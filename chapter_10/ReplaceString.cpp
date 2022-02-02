#include <iostream>
#include <string>

// Replace oldSubStr in s with newSubStr
bool replaceString(std::string &s, const std::string &oldSubStr, const std::string &newSubStr);

int main()
{
    // Prompt the user to enter s, oldSubStr, and newSubStr
    std::cout << "Enter string s, oldSubStr, and newSubStr: ";
    std::string s, oldSubStr, newSubStr;

    bool isReplaced = replaceString(s, oldSubStr, newSubStr);

    if (isReplaced)
    {
        std::cout << "The replaced string is " << s << std::endl;
    }
    else
    {
        std::cout << "No matches" << std::endl;
    }

    return 0;
}

bool replaceString(std::string &s, const std::string &oldSubStr, const std::string &newSubStr)
{
    bool isReplaced = false;
    int currentPosition = 0;
    while (currentPosition < s.length())
    {
        int position = s.find(oldSubStr, currentPosition);
    }
}