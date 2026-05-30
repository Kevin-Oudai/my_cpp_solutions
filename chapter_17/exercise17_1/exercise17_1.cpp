#include <iostream>
#include <vector>
#include "RecursiveLinearSearch.h"

int main()
{
    int size;
    std::cout << "Enter the number of integers: ";
    std::cin >> size;

    std::vector<int> values(size);
    std::cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> values[i];
    }

    int key;
    std::cout << "Enter a key: ";
    std::cin >> key;

    RecursiveLinearSearch searcher;
    int index = searcher.search(values, key);

    if (index == -1)
    {
        std::cout << key << " was not found" << std::endl;
    }
    else
    {
        std::cout << key << " was found at index " << index << std::endl;
    }

    return 0;
}
