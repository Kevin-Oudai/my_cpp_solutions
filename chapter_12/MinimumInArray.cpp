#include <iostream>
#include <string>

template <typename T>
T minimum(T *array, int size)
{
    T minValue = array[0];
    for (int i = 1; i < size; ++i)
    {
        if (array[i] < minValue)
        {
            minValue = array[i];
        }
    }
    return minValue;
}

int main()
{
    int intArray[] = {3, 1, 4, 2};
    double doubleArray[] = {2.5, 4.1, 1.0, 3.5};
    std::string stringArray[] = {"pear", "apple", "orange", "banana"};

    std::cout << "Minimum int: " << minimum(intArray, 4) << std::endl;
    std::cout << "Minimum double: " << minimum(doubleArray, 4) << std::endl;
    std::cout << "Minimum string: " << minimum(stringArray, 4) << std::endl;

    return 0;
}
