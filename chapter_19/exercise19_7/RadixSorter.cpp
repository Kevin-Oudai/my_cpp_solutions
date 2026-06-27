#include "RadixSorter.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void RadixSorter::run() const
{
    std::cout << "Enter number of random integers (1000000 for the exercise): ";
    int size;
    std::cin >> size;

    if (size <= 0)
    {
        std::cout << "Invalid size" << std::endl;
        return;
    }

    int* list = new int[size];
    std::srand(1);
    for (int i = 0; i < size; i++)
        list[i] = std::rand();

    long startTime = static_cast<long>(time(0));
    radixSort(list, size);
    long endTime = static_cast<long>(time(0));

    bool sorted = true;
    for (int i = 1; i < size; i++)
    {
        if (list[i] < list[i - 1])
        {
            sorted = false;
            break;
        }
    }

    std::cout << "Sorted " << size << " integers using radix sort in "
              << endTime - startTime << " seconds" << std::endl;
    std::cout << "First 10 sorted values: ";
    int displayCount = size < 10 ? size : 10;
    for (int i = 0; i < displayCount; i++)
        std::cout << list[i] << " ";
    std::cout << std::endl;
    std::cout << "Sorted correctly: " << (sorted ? "true" : "false") << std::endl;

    delete [] list;
}

void RadixSorter::radixSort(int list[], int size) const
{
    int max = getMax(list, size);

    for (long divisor = 1; max / divisor > 0; divisor *= 10)
    {
        std::vector<int> buckets[10];

        for (int i = 0; i < size; i++)
        {
            int digit = static_cast<int>((list[i] / divisor) % 10);
            buckets[digit].push_back(list[i]);
        }

        int index = 0;
        for (int bucket = 0; bucket < 10; bucket++)
        {
            for (int i = 0; i < static_cast<int>(buckets[bucket].size()); i++)
            {
                list[index++] = buckets[bucket][i];
            }
        }
    }
}

int RadixSorter::getMax(int list[], int size) const
{
    int max = list[0];
    for (int i = 1; i < size; i++)
    {
        if (list[i] > max)
            max = list[i];
    }
    return max;
}
