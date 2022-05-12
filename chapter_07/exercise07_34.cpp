// Exercise 7.34 - Occurences of a specified character
// Revision: Exercise 6.44 - Occurences of a specified character

#include <iostream>
#include <cstring>

int count(const char s[], char a)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == a)
            count++;
    }
    return count;
}

int main()
{
    std::cout << "Enter a string: ";
    char s1[100];
    std::cin.getline(s1, 100);

    std::cout << "Enter a character: ";
    char a;
    std::cin >> a;

    std::cout << a << " appears in " << s1 << " " << count(s1, a) << " times " << std::endl;
    return 0;
}