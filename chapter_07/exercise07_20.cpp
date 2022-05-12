// Exercise 7.20 - Strictly Identical Arrays
#include <iostream>

bool strictlyEqual(const int list1[], const int list2[], int size)
{
    if (list1[0] == list2[0])
    {
        for (int i = 1; i <= list1[0]; i++)
        {
            if (list1[i] != list2[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    const int maxSize = 20;
    int listSize;
    int list1[maxSize], list2[maxSize];
    std::cout << "Enter list1: ";
    std::cin >> listSize;
    list1[0] = listSize;
    for (int i = 1; i <= listSize; i++)
    {
        std::cin >> list1[i];
    }
    std::cout << "Enter list2: ";
    std::cin >> listSize;
    list2[0] = listSize;
    for (int i = 1; i <= listSize; i++)
    {
        std::cin >> list2[i];
    }

    (strictlyEqual(list1, list2, maxSize))
        ? std::cout << "Two lists are strictly identical" << std::endl
        : std::cout << "Two lists are NOT strictly idential" << std::endl;

    return 0;
}