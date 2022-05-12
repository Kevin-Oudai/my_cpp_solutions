// Exercise 5.51 - Business: Check ISBN-13

#include <iostream>
#include <cstring>
int getChecksum(const char s[])
{
    int count = strlen(s);
    int sum = 0;
    if (count == 12)
    {
        for (int i = 0; i < count; i++)
        {
            if (i % 2 == 0)
            {
                sum += static_cast<int>(s[i]) - 48;
            }
            else
            {
                sum += (3 * (static_cast<int>(s[i]) - 48));
            }
        }
        sum = (10 - (sum % 10)) % 10;
        return sum;
    }
    else
        return -1;
}

int main()
{
    std::cout << "Enter the first 12 digits of an ISBN-13 as a string: ";
    char message[14];
    std::cin.getline(message, 13);
    int total = getChecksum(message);
    if (total == -1)
    {
        std::cout << message << " is an invalid input." << std::endl;
    }
    else
    {
        std::cout << "The ISBN-13 number is " << message << total << std::endl;
    }
    return 0;
}