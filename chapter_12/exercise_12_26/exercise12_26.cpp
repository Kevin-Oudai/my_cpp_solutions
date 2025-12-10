#include <iostream>
#include <vector>
#include "Location.h"

Location locateLargest(const std::vector<std::vector<double>> v)
{
    bool found = false;
    int bestRow = 0;
    int bestCol = 0;
    double maxValue = 0;

    for (size_t r = 0; r < v.size(); r++)
    {
        for (size_t c = 0; c < v[r].size(); c++)
        {
            if (!found || v[r][c] > maxValue)
            {
                found = true;
                bestRow = static_cast<int>(r);
                bestCol = static_cast<int>(c);
                maxValue = v[r][c];
            }
        }
    }

    if (!found)
    {
        return Location();
    }
    return Location(bestRow, bestCol, maxValue);
}

int main()
{
    int rows = 0;
    int cols = 0;

    std::cout << "Enter the number of rows and columns of the array: ";
    std::cin >> rows >> cols;

    std::vector<std::vector<double>> values(rows, std::vector<double>(cols));

    std::cout << "Enter the array: ";
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            std::cin >> values[r][c];
        }
    }

    Location result = locateLargest(values);
    std::cout << "The location of the largest element is " << result.getMaxValue()
              << " at (" << result.getRow() << ", " << result.getCol() << ")." << std::endl;

    return 0;
}
