#include "QuickSorter.h"
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

void QuickSorter::run() const
{
    const int INT_SIZE = 9;
    int intList[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
    quickSort(intList, INT_SIZE);
    std::cout << "Sorted int values: ";
    printArray(intList, INT_SIZE);

    const int DOUBLE_SIZE = 6;
    double doubleList[] = {3.4, 1.2, 5.6, 2.2, 2.1, 4.8};
    quickSort(doubleList, DOUBLE_SIZE);
    std::cout << "Sorted double values: ";
    printArray(doubleList, DOUBLE_SIZE);

    const int STRING_SIZE = 5;
    std::string stringList[] = {"Dallas", "Atlanta", "Chicago", "Boston", "Denver"};
    quickSort(stringList, STRING_SIZE);
    std::cout << "Sorted string values: ";
    printArray(stringList, STRING_SIZE);
}
