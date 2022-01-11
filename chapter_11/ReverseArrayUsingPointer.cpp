#include <iostream>

int *reverse(int *list, int size)
{
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        // Swap list[i] with list[j]
        int temp = list[j];
        list[j] = list[i];
        list[i] = temp;
    }

    return list;
}

void printArray(const int *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
    }
}

int main()
{
    int list[] = {1, 2, 3, 4, 5, 6};
    int *p = reverse(list, 6);
    printArray(p, 6);

    return 0;
}