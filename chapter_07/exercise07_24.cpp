// Pattern Recognition: Consecutive four equal numbers

#include <iostream>

bool isConsecutiveFour(const int values[], int size)
{
    for (int i = 0; i < size - 4; i++)
    {
        if (values[i] == values[i + 1] && values[i + 1] == values[i + 2] && values[i + 2] == values[i + 3])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    const int SIZE = 80;
    int values[SIZE];
    int numberOfValues;
    std::cout << "Enter the number of values: ";
    std::cin >> numberOfValues;

    std::cout << "Enter the values: ";
    for (int i = 0; i < numberOfValues; i++)
    {
        std::cin >> values[i];
    }

    (isConsecutiveFour(values, numberOfValues))
        ? std::cout << "The list has four consecutive numbers" << std::endl
        : std::cout << "The list does NOT have 4 consecutive numbers" << std::endl;

    return 0;
}