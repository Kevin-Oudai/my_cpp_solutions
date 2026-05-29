#include <iostream>
#include <vector>

template <typename T>
void removeDuplicate(std::vector<T> &v)
{
    std::vector<T> uniqueValues;
    for (const T &value : v)
    {
        bool exists = false;
        for (const T &u : uniqueValues)
        {
            if (u == value)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            uniqueValues.push_back(value);
        }
    }
    v.swap(uniqueValues);
}

int main()
{
    const int COUNT = 10;
    std::vector<int> numbers(COUNT);

    std::cout << "Enter ten integers: ";
    for (int i = 0; i < COUNT; i++)
    {
        std::cin >> numbers[i];
    }

    removeDuplicate(numbers);

    std::cout << "The distinct integers are";
    for (int value : numbers)
    {
        std::cout << " " << value;
    }
    std::cout << std::endl;

    return 0;
}
