// Exercise 8.5 - Algebra: add two matrices

#include <iostream>
#include <iomanip>

const int N = 3;

void addMatrix(const double a[][N], const double b[][N], double c[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main()
{
    std::cout << "Enter matrix1: ";
    double a[N][N] = {}, b[N][N] = {}, c[N][N] = {};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> a[i][j];
        }
    }

    std::cout << "Enter matrix2: ";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> b[i][j];
        }
    }

    addMatrix(a, b, c);
    std::cout << "The addition of the matrices is" << std::endl;
    for (int i = 0; i < N; i++)
    {
        for (int aElements = 0; aElements < N; aElements++)
        {
            std::cout << std::setw(4) << a[i][aElements] << " ";
        }

        (i % 2 == 1)
            ? std::cout << std::setw(4) << "   +   "
            : std::cout << std::setw(4) << "       ";

        for (int bElements = 0; bElements < N; bElements++)
        {
            std::cout << std::setw(4) << b[i][bElements] << " ";
        }

        (i % 2 == 1)
            ? std::cout << std::setw(4) << "   =   "
            : std::cout << std::setw(4) << "       ";

        for (int j = 0; j < N; j++)
        {
            std::cout << std::setw(4) << c[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}