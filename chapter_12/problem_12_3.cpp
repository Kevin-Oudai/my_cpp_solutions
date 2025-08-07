#include <iostream>
#include <string>
#include <utility>

// Generic bubble sort that sorts an array of type T in ascending order
template <typename T>
void bubbleSort(T* list, int listSize)
{
    for (int i = 0; i < listSize - 1; ++i)
    {
        for (int j = 0; j < listSize - i - 1; ++j)
        {
            if (list[j] > list[j + 1])
            {
                std::swap(list[j], list[j + 1]);
            }
        }
    }
}

// Helper function to print an array
template <typename T>
void printArray(const T* list, int listSize)
{
    for (int i = 0; i < listSize; ++i)
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
    int integers[] = {3, 1, 4, 1, 5, 9};
    double decimals[] = {2.7, 3.1, 4.1, 5.9, 2.6};
    std::string strings[] = {"orange", "apple", "banana", "grape"};

    int intCount = sizeof(integers) / sizeof(integers[0]);
    int doubleCount = sizeof(decimals) / sizeof(decimals[0]);
    int stringCount = sizeof(strings) / sizeof(strings[0]);

    std::cout << "Before sorting integers: ";
    printArray(integers, intCount);
    bubbleSort(integers, intCount);
    std::cout << "After sorting integers:  ";
    printArray(integers, intCount);

    std::cout << "\nBefore sorting decimals: ";
    printArray(decimals, doubleCount);
    bubbleSort(decimals, doubleCount);
    std::cout << "After sorting decimals:  ";
    printArray(decimals, doubleCount);

    std::cout << "\nBefore sorting strings:  ";
    printArray(strings, stringCount);
    bubbleSort(strings, stringCount);
    std::cout << "After sorting strings:   ";
    printArray(strings, stringCount);

    return 0;
}

