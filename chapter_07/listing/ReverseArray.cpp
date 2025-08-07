// Listing 7.7 - ReverseArray.cpp
#include <iostream>

void reverse(const int list[], int newList[], int size)
{
    for (int i = 0, j = size - 1; i < size; i++, j--)
    {
        newList[j] = list[i];
    }
}

void printArray(const int list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
    }
}

int main()
{
    const int SIZE = 6;
    int list[] = {1, 2, 3, 4, 5, 6};
    int newList[SIZE];

    reverse(list, newList, SIZE);
    std::cout << "The original array: ";
    printArray(list, SIZE);
    std::cout << std::endl;

    std::cout << "The reversed array: ";
    printArray(newList, SIZE);
    std::cout << std::endl;
    return 0;
}