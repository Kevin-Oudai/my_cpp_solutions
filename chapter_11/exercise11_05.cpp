#include <iostream>

int largestElement(const int *array, int size)
{
    int largest = array[0];
    for (int i = 1; i < size; i++)
    {
        if (largest < array[i])
        {
            largest = array[i];
        }
    }
    return largest;
}

int main()
{
    int array[8] = {6, 7, 9, 10, 15, 3, 99, -21};
    int largest = largestElement(array, 8);
    std::cout << "The largest element of the array is: " << largest << std::endl;
    return 0;
}