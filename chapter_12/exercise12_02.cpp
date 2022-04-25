#include <iostream>
#include <string>

template <typename T>
void selectionSort(T list[], int listSize)
{
    for (int i = 0; i < listSize - 1; i++)
    {
        T currentMin = list[i];
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
    for (int i = 0; i < listSize; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int integers[] = {2, 6, 9, 10, 30, 21};
    double decimals[] = {1.2, 3.9, 2.1, 9.3, 4.5, 3.5};
    std::string strings[] = {"Kevin", "Venita", "Athena"};
    selectionSort(integers, 6);
    selectionSort(decimals, 6);
    selectionSort(strings, 3);

    return 0;
}