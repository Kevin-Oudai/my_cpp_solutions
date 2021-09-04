// Listing 8.1 - PassTwoDimensionalArray.cpp

#include <iostream>

const int COLUMN_SIZE = 4;

int sum(const int a[][COLUMN_SIZE], int rowSize)
{
    int total = 0;
    for (int row = 0; row < rowSize; row++)
    {
        for (int column = 0; column < COLUMN_SIZE; column++)
        {
            total += a[row][column];
        }
    }
    return total;
}

int main()
{
    const int ROW_SIZE = 3;
    int m[ROW_SIZE][COLUMN_SIZE];
    std::cout << "Enter " << ROW_SIZE << " rows and " << COLUMN_SIZE << " columns: " << std::endl;
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
            std::cin >> m[i][j];
        }
    }
    std::cout << "\nSum of all elements is " << sum(m, ROW_SIZE) << std::endl;
    return 0;
}