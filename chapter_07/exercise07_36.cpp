// Exercise 7.36 - Swap Case
// Revision: Exercise 6.46 - Swap Case

#include <iostream>
#include <cstring>

void swapCase(const char s1[], char s2[])
{
    int ascii = 0;
    int i = 0;
    for (i; i < strlen(s1); i++)
    {
        std::cout << s1[i];
        ascii = static_cast<int>(s1[i]);
        if (ascii >= 65 && ascii <= 90)
        {
            s2[i] = static_cast<char>(ascii + 32);
            std::cout << " " << s2[i] << std::endl;
        }
        else if (ascii >= 97 && ascii <= 122)
        {
            s2[i] = static_cast<char>(ascii - 32);
            std::cout << " " << s2[i] << std::endl;
        }
        else
        {
            s2[i] = s1[i];
            std::cout << " " << s2[i] << std::endl;
        }
    }
    s2[i] = s1[i];
}

int main()
{
    std::cout << "Enter a string: ";
    char s1[100], s2[100];
    std::cin.getline(s1, 100);

    swapCase(s1, s2);
    std::cout << "The new string is: " << s2 << std::endl;
    return 0;
}