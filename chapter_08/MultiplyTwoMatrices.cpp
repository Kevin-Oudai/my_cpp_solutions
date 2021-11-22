#include <iostream>

const int N = 3;

void multiplyMatrix(const double a[][N], const double b[][N], double c[][N])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
        }
    }
}

void display(const double a[][N], const double b[][N], double c[][N])
{
}

int main()
{
    double a[3][3], b[3][3], c[3][3];
    std::cout << "Enter matrix1: ";
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
    multiplyMatrix(a, b, c);
    display(a, b, c);
    return 0;
}