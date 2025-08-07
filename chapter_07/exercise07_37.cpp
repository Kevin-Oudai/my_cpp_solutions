// Exercise 7.37 - Count occurence of each letter in a string

#include <iostream>
#include <cstring>

int countLetter(const char s[], char a)
{
    int count = 0;
    int asci;
    for (int i = 0; i < strlen(s); i++)
    {
        asci = static_cast<int>(s[i]);
        if (asci >= 65 && asci <= 90)
        {
            asci += 32;
        }
        if (static_cast<char>(asci) == a)
            count++;
    }
    return count;
}

void count(const char s[], int counts[])
{
    int num = 0;
    int countsPosition = 0;
    for (int i = 97; i < 123; i++)
    {
        num = countLetter(s, static_cast<char>(i));
        counts[countsPosition++] = num;
    }
}

int main()
{
    int counts[26] = {};
    std::cout << "Enter a string: ";
    char s[100];
    std::cin.getline(s, 100);
    count(s, counts);

    for (int i = 0; i < 26; i++)
    {
        if (counts[i] != 0)
        {
            std::cout << static_cast<char>(97 + i) << ": " << counts[i] << " times." << std::endl;
        }
    }
    return 0;
}