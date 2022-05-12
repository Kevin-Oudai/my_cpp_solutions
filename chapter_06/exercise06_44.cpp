// Exercise 6.44 - Occurences of a specified character

#include <iostream>
#include <string>

int count(const std::string &s, char a)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (a == s.at(i))
            count++;
    }
    return count;
}

int main()
{
    std::cout << "Enter a string: ";
    std::string s1;
    std::getline(std::cin, s1);

    std::cout << "Enter a character: ";
    char a;
    std::cin >> a;

    std::cout << a << " appears in " << s1 << " " << count(s1, a) << " times " << std::endl;
    return 0;
}