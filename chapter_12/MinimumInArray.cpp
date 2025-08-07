// Codex Prompt: Problem 12.1 (Minimum in array)
//
// Write a generic C++ function named `minimum` that returns the minimum element from an array.
// The function should accept two parameters:
// - A pointer to an array of a generic type `T`.
// - An integer representing the size of the array.
//
// Then write a `main()` function to test `minimum` with three types of arrays:
// - An array of `int`
// - An array of `double`
// - An array of `std::string`
//
// Ensure the function works correctly with all three types and print the results.
//
// Use `template <typename T>` to define the generic function.
// Include appropriate headers and ensure the program compiles as a standalone C++ file.

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
