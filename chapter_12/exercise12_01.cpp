#include <iostream>

template<typename T>
T minElement(T list[], int size)
{
    T min = list[0];
    for (int i = 1; i < size; i++)
    {
        if (min > list[i])
        {
            min = list[i];
        }
    }
    return min;
}

int main()
{
    int intArray[] = {2, 5, 4, 7, 9, 1};
    
    return 0;
}