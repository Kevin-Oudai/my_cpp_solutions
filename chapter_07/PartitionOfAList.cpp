// Exercise 7.28 - Partition of a list

#include <iostream>

void swap(int list[], int index1, int index2)
{
    int temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}

void displayList(int list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

int partition(int list[], int size)
{
    int start = size / 2;
    int end = size;
    int pivot = list[0];
    int pivotIndex = 0;
    bool isCorrect = false;
    for (int i = 0; i < size; i++)
    {
        for (start; start < end; start++)
        {
            if (pivot > list[start] && i % 2 == 0)
            {
                swap(list, pivotIndex, start);
                pivotIndex = start;
            }
            else if (pivot < list[start] && i % 2 == 1)
            {
                swap(list, pivotIndex, start);
                pivotIndex = start;
                break;
            }
        }
        start = 0;
        end = size;
    }

    return pivotIndex;
}

int main()
{
    int list[80] = {};
    std::cout << "Enter list: ";
    int size;
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cin >> list[i];
    }
    displayList(list, size);
    int pivot = partition(list, size);
    displayList(list, size);

    return 0;
}