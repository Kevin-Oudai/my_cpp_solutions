#include "LinearEquationSolver.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace
{
double determinant(const std::vector<std::vector<double>> &matrix)
{
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

bool hasValidSize(const std::vector<std::vector<double>> &a, const std::vector<double> &b)
{
    if (a.size() != 3 || b.size() != 3)
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        if (a[i].size() != 3)
        {
            return false;
        }
    }

    return true;
}

std::vector<std::vector<double>> replaceColumn(std::vector<std::vector<double>> a,
                                               const std::vector<double> &b,
                                               int column)
{
    for (int i = 0; i < 3; i++)
    {
        a[i][column] = b[i];
    }

    return a;
}
}

std::vector<double> solveLinearEquation(std::vector<std::vector<double>> a, std::vector<double> b)
{
    if (!hasValidSize(a, b))
    {
        throw std::invalid_argument("The matrix and vector sizes must be 3");
    }

    double detA = determinant(a);
    if (std::fabs(detA) < 0.0000000001)
    {
        throw std::runtime_error("The equation has no solution");
    }

    std::vector<double> result(3);
    result[0] = determinant(replaceColumn(a, b, 0)) / detA;
    result[1] = determinant(replaceColumn(a, b, 1)) / detA;
    result[2] = determinant(replaceColumn(a, b, 2)) / detA;

    return result;
}

void LinearEquationSolver::run() const
{
    std::vector<std::vector<double>> a(3, std::vector<double>(3));
    std::vector<double> b(3);

    std::cout << "Enter a11, a12, a13, a21, a22, a23, a31, a32, a33:" << std::endl;
    std::cin >> a[0][0] >> a[0][1] >> a[0][2]
             >> a[1][0] >> a[1][1] >> a[1][2]
             >> a[2][0] >> a[2][1] >> a[2][2];

    std::cout << "Enter b1, b2, b3:" << std::endl;
    std::cin >> b[0] >> b[1] >> b[2];

    try
    {
        std::vector<double> solution = solveLinearEquation(a, b);
        std::cout << "The solution is " << solution[0] << " "
                  << solution[1] << " " << solution[2] << std::endl;
    }
    catch (const std::runtime_error &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (const std::invalid_argument &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
