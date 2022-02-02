// Exercise 8.2 - Sum the major diagonal in a matrix

#include <iostream>

const int SIZE = 4;
double sumMajorDiagonal(const double m[][SIZE])
{
    double total = 0;
    for (int i = 0; i < SIZE; i++)
    {
        total += m[i][i];
    }
    return total;
}

int main()
{
    std::cout << "Enter a 4-by-4 matrix row by row: " << std::endl;
    double matrix[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    double total = sumMajorDiagonal(matrix);
    std::cout << "Sum of the elements in the major diagonal is " << total << std::endl;

    return 0;
}