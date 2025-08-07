// Exercise 7.27 - Sorted?

#include <iostream>

bool isSorted(const int list[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (list[i] > list[i + 1])
        {
            std::cout << list[i] << " > " << list[i + 1] << std::endl;
            return false;
        }
    }
    return true;
}

int main()
{
    int list[80];
    std::cout << "Enter list: ";
    std::cin >> list[0];
    for (int i = 1; i <= list[0]; i++)
    {
        std::cin >> list[i];
    }
    isSorted(list, list[0])
        ? std::cout << "The list is already sorted" << std::endl
        : std::cout << "The list is not sorted" << std::endl;
    return 0;
}
