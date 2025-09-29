#include <iostream>
#include <string>

template <typename T>
T findMin(T arr[], int size)
{
    T min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int intArray[] = {10, 5, 15, 3, 20};
    double doubleArray[] = {3.14, 1.59, 2.65, 5.35};
    std::string stringArray[] = {"Apple", "Orange", "Banana", "Peach"};

    std::cout << "Min in intArray: " << findMin(intArray, 5) << std::endl;
    std::cout << "Min in doubleArray: " << findMin(doubleArray, 4) << std::endl;
    std::cout << "Min in stringArray: " << findMin(stringArray, 4) << std::endl;
    return 0;
}