// Exercise 7.26 - Merge two sorted
#include <iostream>

void merge(const int list1[], int size1, const int list2[], int size2, int list3[])
{
    int list3Count, list2Count = 1, list1Count = 1;
    for (int i = 0; i < size1 + size2; i++)
    {
        list1[list1Count] < list2[list2Count]
            ? list3[i] = list1[list1Count++]
            : list3[i] = list2[list2Count++];
    }
}

int main()
{
    std::cout << "Enter list1: ";
    int list1[80], list3[80];
    std::cin >> list1[0];

    for (int i = 1; i <= list1[0]; i++)
    {
        std::cin >> list1[i];
    }

    std::cout << "Enter list2: ";
    int list2[80];
    std::cin >> list2[0];

    for (int i = 1; i <= list2[0]; i++)
    {
        std::cin >> list2[i];
    }

    merge(list1, list1[0], list2, list2[0], list3);
    std::cout << "The merged list is ";
    for (int i = 0; i < list1[0] + list2[0]; i++)
    {
        std::cout << list3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}