#include <iostream>

int main()
{
    int size, odd = 0, even = 0;
    typedef int *intPtr;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    intPtr values = new int[size];

    std::cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> *(values + i);
        (*(values + i) % 2 == 0) ? even++ : odd++;
    }

    intPtr oddValues = new int[odd];
    intPtr evenValues = new int[even];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (*(values + i) % 2 == 0)
        {
            *(evenValues + j++) = *(values + i);
        }
    }

    for (int i = 0, j = 0; i < size; i++)
    {
        if (*(values + i) % 2 == 1)
        {
            *(oddValues + j++) = *(values + i);
        }
    }

    std::cout << "There are " << even << " numbers...";
    for (int i = 0; i < even; i++)
    {
        std::cout << *(evenValues + i) << " ";
    }
    std::cout << std::endl;

    std::cout << "There are " << odd << " numbers...";
    for (int i = 0; i < odd; i++)
    {
        std::cout << *(oddValues + i) << " ";
    }
    std::cout << std::endl;

    return 0;
}