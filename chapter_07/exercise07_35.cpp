// Exercise 7.35 - Count the letters in a string

#include <iostream>
#include <cstring>

int countLetters(const char s[])
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        int charInt = static_cast<int>(s[i]);
        if ((charInt >= 65 && charInt <= 90) || (charInt >= 97 && charInt <= 122))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    std::cout << "Enter a string: ";
    char s[100];
    std::cin.getline(s, 100);
    std::cout << "The number of letters in \"" << s << "\" is " << countLetters(s) << std::endl;
    return 0;
}