// Exercise 6.46 - Swap Case

#include <iostream>
#include <string>

std::string swapCase(const std::string &s)
{
    std::string newString = "";
    int ascii = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ascii = static_cast<int>(s.at(i));
        if (ascii >= 65 && ascii <= 90)
        {
            newString += static_cast<char>(ascii + 32);
        }
        else if (ascii >= 97 && ascii <= 122)
        {
            newString += static_cast<char>(ascii - 32);
        }
        else
        {
            newString += s.at(i);
        }
    }
    return newString;
}

int main()
{
    std::cout << "Enter a string: ";
    std::string s1, newString;
    std::getline(std::cin, s1);

    newString = swapCase(s1);
    std::cout << "The new string is: " << newString << std::endl;
    return 0;
}