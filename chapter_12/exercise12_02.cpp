#include <iostream>
#include <string>
#include <utility>

// Generic selection sort that sorts an array of type T in ascending order
template <typename T>
void selectionSort(T* list, int listSize)
{
    for (int i = 0; i < listSize - 1; i++)
    {
        int currentMinIndex = i;
        for (int j = i + 1; j < listSize; j++)
        {
            if (list[j] < list[currentMinIndex])
            {
                currentMinIndex = j;
            }
        }

        if (currentMinIndex != i)
        {
            std::swap(list[i], list[currentMinIndex]);
        }
    }
}

// Helper function to print an array
template <typename T>
void printArray(const T* list, int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        std::cout << list[i];
        if (i < listSize - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << '\n';
}

int main()
{
    int integers[] = {2, 6, 9, 10, 30, 21};
    double decimals[] = {1.2, 3.9, 2.1, 9.3, 4.5, 3.5};
    std::string strings[] = {"Kevin", "Venita", "Athena"};

    int intCount = sizeof(integers) / sizeof(integers[0]);
    int doubleCount = sizeof(decimals) / sizeof(decimals[0]);
    int stringCount = sizeof(strings) / sizeof(strings[0]);

    std::cout << "Before sorting integers: ";
    printArray(integers, intCount);
    selectionSort(integers, intCount);
    std::cout << "After sorting integers:  ";
    printArray(integers, intCount);

    std::cout << "\nBefore sorting decimals: ";
    printArray(decimals, doubleCount);
    selectionSort(decimals, doubleCount);
    std::cout << "After sorting decimals:  ";
    printArray(decimals, doubleCount);

    std::cout << "\nBefore sorting strings:  ";
    printArray(strings, stringCount);
    selectionSort(strings, stringCount);
    std::cout << "After sorting strings:   ";
    printArray(strings, stringCount);

    return 0;
}

