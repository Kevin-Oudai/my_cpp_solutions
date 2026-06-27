#include "BubbleSorter.h"
#include <iostream>
#include <string>

namespace
{
template<typename T>
void printArray(T list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}
}

void BubbleSorter::run() const
{
    const int INT_SIZE = 9;
    int intList[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
    bubbleSort(intList, INT_SIZE);
    std::cout << "Sorted int values: ";
    printArray(intList, INT_SIZE);

    const int STRING_SIZE = 5;
    std::string stringList[] = {"Dallas", "Atlanta", "Chicago", "Boston", "Denver"};
    bubbleSort(stringList, STRING_SIZE);
    std::cout << "Sorted string values: ";
    printArray(stringList, STRING_SIZE);
}
