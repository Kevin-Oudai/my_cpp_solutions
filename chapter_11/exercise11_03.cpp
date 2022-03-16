// Exercise 7.14 - Bubble Sort

#include <iostream>
#include <cstdlib>
#include <ctime>

void bubbleSort(int *const array, int size)
{
    bool changed = true;
    double temp;
    do
    {
        changed = false;
        for (int j = 0; j < size - 1; j++)
        {
            if (*(array + j) > *(array + j + 1))
            {
                temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
                changed = true;
            }
        }
    } while (changed);
}

int main()
{
    srand(time(0));
    const int SIZE = 10;
    int *const testArray = new int[SIZE];
    std::cout << "Array before sort: ";
    for (int i = 0; i < SIZE; i++)
    {
        testArray[i] = (rand() % 100) / 10.0;
        std::cout << testArray[i] << ", ";
    }
    std::cout << std::endl;

    bubbleSort(testArray, SIZE);
    std::cout << "Array after sort: ";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << testArray[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}