#include <iostream>

void sortArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        int currentMinIndex = i;
        int currentMin = array[i];
        for (int j = i + 1; j < arraySize; j++)
        {
            if (array[i] > array[j])
            {
                currentMinIndex = j;
                currentMin = array[j];
            }
        }
        array[currentMinIndex] = array[i];
        array[i] = currentMin;
    }
}

bool isEqual(const int list1[], const int list2[], int size)
{
    int newList1[20], newList2[20];
    for (int i = 0; i < size; i++)
    {
        newList1[i] = list1[i];
        newList2[i] = list2[i];
    }
    sortArray(newList1, size);
    sortArray(newList2, size);
    for (int i = 0; i < size; i++)
    {
        if (newList1[i] != newList2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << "Enter list1: ";
    int list1[20], list2[20], size1, size2;
    std::cin >> size1;
    for (int i = 0; i < size1; i++)
    {
        std::cin >> list1[i];
    }
    std::cout << "Enter list2: ";
    std::cin >> size2;
    for (int i = 0; i < size2; i++)
    {
        std::cin >> list2[i];
    }
    if (size1 == size2 && isEqual(list1, list2, size1))
    {
        std::cout << "Two lists are identical" << std::endl;
    }
    else
    {
        std::cout << "Two lists are not identical" << std::endl;
    }

    return 0;
}