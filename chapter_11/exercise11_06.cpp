#include <iostream>
#include <string>

int indexOf(char num)
{
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 10; i++)
    {
        if (num == numbers[i])
        {
            return i;
        }
    }
    return -1;
}

int *count(const std::string &s)
// This function counts the occurence of each digit in a string
{
    int index;
    int *countNumbers = new int[10];
    for (int i = 0; i < 10; i++)
    {
        countNumbers[i] = 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        index = indexOf(s[i]);
        if (index != -1)
        {
            countNumbers[index]++;
        }
    }
    return countNumbers;
}

void count(const std::string &s, int counts[], int size)
{
    int index;
    for (int i = 0; i < s.length(); i++)
    {
        index = indexOf(s[i]);
        if (index != -1)
        {
            counts[index]++;
        }
    }
}

int main()
{
    std::string a = "SSN is 343 32 4545 and ID is 434 34 4323";
    int *result = count(a);
    std::cout << "Pointer result: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    int counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::cout << "Array result: ";
    count(a, counts, 10);
    for (int i = 0; i < 10; i++)
    {
        std::cout << counts[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}