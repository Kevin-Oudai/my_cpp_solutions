#include <iostream>
#include <string>

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
            T temp = list[i];
            list[i] = list[currentMinIndex];
            list[currentMinIndex] = temp;
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
    std::cout << std::endl;
}

int main()
{
    int integers[] = {2, 6, 9, 10, 30, 21};
    double decimals[] = {1.2, 3.9, 2.1, 9.3, 4.5, 3.5};
    std::string strings[] = {"Kevin", "Venita", "Athena"};

    std::cout << "Before sorting integers: ";
    printArray(integers, 6);
    selectionSort(integers, 6);
    std::cout << "After sorting integers:  ";
    printArray(integers, 6);

    std::cout << "\nBefore sorting decimals: ";
    printArray(decimals, 6);
    selectionSort(decimals, 6);
    std::cout << "After sorting decimals:  ";
    printArray(decimals, 6);

    std::cout << "\nBefore sorting strings:  ";
    printArray(strings, 3);
    selectionSort(strings, 3);
    std::cout << "After sorting strings:   ";
    printArray(strings, 3);

    return 0;
}

