// This program is not working because random_shuffle was deprecated.
#include <iostream>
#include <algorithm>

void printArray(const int *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int list[] = {4, 2, 3, 6, 5, 1};
    printArray(list, 6);

    int *min = std::min_element(list, list + 6);
    int *max = std::max_element(list, list + 6);
    std::cout << "The min value is " << *min << " at index "
              << (min - list) << std::endl;
    std::cout << "The max value is " << *max << " at index "
              << (max - list) << std::endl;

    // std::random_shuffle(list, list + 6);
    printArray(list, 6);

    std::sort(list, list + 6);
    printArray(list, 6);

    int key = 4;
    int *p = std::find(list, list + 6, key);
    if (p != list + 6)
        std::cout << "The value " << *p << " is found at position "
                  << (p - list) << std::endl;
    else
        std::cout << "The value " << *p << " is not found" << std::endl;

    return 0;
}