#include <iostream>
#include <iomanip>

void display(double matrix[][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << std::setprecision(1) << std::fixed << std::showpoint
                      << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void inverse(const double A[][2], double inverseOfA[][2])
{
    double determinant = 1.0 / ((A[0][0] * A[1][1]) - (A[0][1] * A[1][0]));
    inverseOfA[0][0] = determinant * A[1][1];
    inverseOfA[0][1] = -determinant * A[0][1];
    inverseOfA[1][0] = -determinant * A[1][0];
    inverseOfA[1][1] = determinant * A[0][0];
    display(inverseOfA);
}

int main()
{
    std::cout << "Enter a, b, c, d: ";
    double matrix[2][2], inverseMatrix[2][2] = {};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    inverse(matrix, inverseMatrix);
}