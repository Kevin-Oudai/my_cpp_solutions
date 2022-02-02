#include <iostream>

void displayResult(int location[])
{
    std::cout << "The location of the largest element is at (" << location[0] << ", " << location[1] << ")" << std::endl;
}

void locateLargest(const double a[][4], int location[])
{
    double largest = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (largest < a[i][j])
            {
                largest = a[i][j];
                location[0] = i;
                location[1] = j;
            }
        }
    }
    displayResult(location);
}

int main()
{
    std::cout << "Enter the array: " << std::endl;
    double array[3][4] = {};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cin >> array[i][j];
        }
    }
    int location[2] = {};
    locateLargest(array, location);

    return 0;
}