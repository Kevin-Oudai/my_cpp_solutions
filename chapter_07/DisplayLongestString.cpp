
// Exercise 7.32 - Display longest string
// Revision: Exercise 6.42 - Display Longest String

#include <iostream>
#include <string>
#include <cstring>

std::string longest(const char s1[], const char s2[], char longestString[])
{
    int s1Size = strlen(s1);
    int s2Size = strlen(s2);
    if (s1Size > s2Size)
    {
        strcpy(longestString, s1);
    }
    else
    {
        strcpy(longestString, s2);
    }

    return longestString;
}

int main()
{
    std::cout << "Enter the first string: ";
    char s1[100], s2[100], longestString[100];
    std::cin.getline(s1, 100);

    std::cout << "Enter the second string: ";
    std::cin.getline(s2, 100);

    std::cout << "The longest string is: " << longest(s1, s2, longestString) << std::endl;
    return 0;
}