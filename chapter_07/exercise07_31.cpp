// Exercise 7.31 - Common Elements

#include <iostream>

void displayCommon(int list1[], int list2[], int size)
{
    std::cout << "The common elements are ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (list1[i] == list2[j])
            {
                std::cout << list1[i] << " ";
            }
        }
    }
    std::cout << std::endl;
}

int main()
{
    const int size = 10;
    int first[size] = {}, second[size] = {};
    std::cout << "Enter list1: ";
    for (int i = 0; i < 10; i++)
    {
        std::cin >> first[i];
    }
    std::cout << "Enter list2: ";
    for (int i = 0; i < 10; i++)
    {
        std::cin >> second[i];
    }
    displayCommon(first, second, size);
    return 0;
}