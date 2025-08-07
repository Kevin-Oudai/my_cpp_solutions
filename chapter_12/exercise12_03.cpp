#include <iostream>
#include <string>

template <typename T>
void bubbleSort(T list[], int listSize)
{
    bool changed = true;
    T temp;
    do
    {
        changed = false;
        for (int j = 0; j < listSize - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                changed = true;
            }
        }
    } while (changed);

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
    bubbleSort(integers, 6);
    bubbleSort(decimals, 6);
    bubbleSort(strings, 3);

    return 0;
}