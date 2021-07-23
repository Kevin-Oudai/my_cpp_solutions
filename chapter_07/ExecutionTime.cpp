// Exercise 7.12 - Execution Time

#include <iostream>
#include <ctime>
#include <cstdlib>

int linearSearch(const int list[], int key, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (key == list[i])
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(const int list[], int key, int listSize)
{
    int low = 0;
    int high = listSize - 1;

    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (key < list[mid])
            high = mid - 1;
        else if (key == list[mid])
            return mid;
        else
            low = mid + 1;
    }

    return -low - 1;
}

void selectionSort(int list[], int listSize)
{
    for (int i = 0; i < listSize - 1; i++)
    {
        int currentMin = list[i];
        int currentMinIndex = i;

        for (int j = i + 1; j < listSize; j++)
        {
            if (currentMin > list[j])
            {
                currentMin = list[j];
                currentMinIndex = j;
            }
        }

        if (currentMinIndex != i)
        {
            list[currentMinIndex] = list[i];
            list[i] = currentMin;
        }
    }
}

int main()
{
    const int SIZE = 100000;
    int binaryArray[SIZE], linearArray[SIZE];
    int count = 0;
    while (count < SIZE)
    {
        binaryArray[count] = rand();
        linearArray[count] = binaryArray[count];
        count++;
    }
    int key = rand();

    long linearStartTime = time(0);
    int linearIndex = linearSearch(linearArray, key, SIZE);
    long linearEndTime = time(0);
    long linearExecutionTime = linearEndTime - linearStartTime;

    long binaryStartTime = time(0);
    selectionSort(binaryArray, SIZE);
    int binaryIndex = binarySearch(binaryArray, key, SIZE);
    long binaryEndTime = time(0);
    long binaryExecutionTime = binaryEndTime - binaryStartTime;

    std::cout << "The execution time for linear search is: " << linearExecutionTime << std::endl;
    std::cout << "The execution time for binary search is: " << binaryExecutionTime << std::endl;
    return 0;
}