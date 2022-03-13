#include <iostream>
#include "Location.h"

const int ROW_SIZE = 3;
const int COLUMN_SIZE = 4;
Location locateLargest(const double a[][COLUMN_SIZE])
{
    int lCol = 0;
    int lRow = 0;
    double max = a[lRow][lCol];
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 1; j < COLUMN_SIZE; j++)
        {
            if (max < a[i][j])
            {
                lCol = j;
                lRow = i;
                max = a[i][j];
            }
        }
    }
    return Location(lRow, lCol, max);
}

int main()
{
    double matrix[ROW_SIZE][COLUMN_SIZE] = {};
    std::cout << "Enter a 3-by-4 two-dimensional array: ";
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    Location result = locateLargest(matrix);

    std::cout << "The location of the largest element is " << result.getMaxValue() << " as location ("
              << result.getRow() << ", " << result.getCol() << ")." << std::endl;
    return 0;
}