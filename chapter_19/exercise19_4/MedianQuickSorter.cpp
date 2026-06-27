#include "MedianQuickSorter.h"
#include <iostream>

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

void MedianQuickSorter::run() const
{
    const int SIZE = 10;
    int list[] = {5, 2, 9, 3, 8, 4, 0, 1, 6, 7};

    medianQuickSort(list, SIZE);

    std::cout << "Sorted values: ";
    printArray(list, SIZE);
}
