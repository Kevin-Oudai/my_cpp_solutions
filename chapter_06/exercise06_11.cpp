// Exercise 6.11 - Display ASCII values

#include <iostream>

void printASCII(char ch1, char ch2, int numberPerLine)
{
    int first = static_cast<int>(ch1);
    int last = static_cast<int>(ch2);
    int count = 0;
    for (int i = first; i <= last; i++)
    {
        std::cout << static_cast<char>(i) << " ";
        count++;
        if (count % 6 == 0)
        {
            std::cout << std::endl;
        }
    }
}

int main()
{
    char ch1 = 'a';
    char ch2 = 'm';
    int numberPerLine = 6;
    printASCII(ch1, ch2, numberPerLine);
    return 0;
}