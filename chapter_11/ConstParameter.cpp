#include <iostream>

void printArray(const int *, const int);

int main()
{
    int list[6] = {11, 12, 13, 14, 15, 16};
    printArray(list, 6);
    return 0;
}

void printArray(const int *list, const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
    }
}