// Exercise 8.1 - Sum elements column by columns

#include <iostream>

const int SIZE = 4;

double sumColumn(const double m[][SIZE], int rowSize, int columnIndex)
{
    double sum = 0;
    for (int i = 0; i < rowSize; i++)
    {
        sum += m[i][columnIndex];
    }
    return sum;
}

int main()
{
    const int row = 3;
    const int col = 4;

    std::cout << "Enter a 3-by-4 matrix row by row: ";
    double matrix[row][col] = {};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    for (int k = 0; k < col; k++)
    {
        double total = sumColumn(matrix, row, k);
        std::cout << "Sum of the elements at column " << k << " is " << total << std::endl;
    }
    return 0;
}