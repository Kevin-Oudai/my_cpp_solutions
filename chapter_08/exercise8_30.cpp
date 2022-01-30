#include <iostream>
#include <iomanip>

const int SIZE = 2;

bool linearEquation(const double a[][SIZE], const double b[], double result[])
{
    double D = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    if (D == 0)
    {
        return false;
    }
    else
    {
        result[0] = (b[0] * a[1][1] - b[1] * a[0][1]) / D;
        result[1] = (b[1] * a[0][0] - b[0] * a[1][0]) / D;
        return true;
    }
}

int main()
{
    double result[SIZE] = {}, a[SIZE][SIZE] = {}, b[SIZE] = {};

    std::cout << "Enter the 2-by-3 array that represent the equations: ";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        std::cin >> b[i];
    }

    if (!linearEquation(a, b, result))
    {
        std::cout << "The equation has no solution" << std::endl;
    }
    else
    {
        std::cout << std::setprecision(1) << std::showpoint << std::fixed;
        std::cout << "x is " << result[0] << " and y is " << result[1] << std::endl;
    }
    return 0;
}