#include <iostream>

void display(double inverseOfA[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << inverseOfA[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double determinant(const double A[][3])
{
    double p1 = A[0][0] * A[1][1] * A[2][2];
    double p2 = A[2][0] * A[0][1] * A[1][2];
    double p3 = A[0][2] * A[1][0] * A[2][1];
    double p4 = A[0][2] * A[1][1] * A[2][0];
    double p5 = A[0][0] * A[1][2] * A[2][1];
    double p6 = A[2][2] * A[1][0] * A[0][1];
    double determinant = p1 + p2 + p3 - p4 - p5 - p6;
    return determinant;
}

void inverse(const double A[][3], double inverseOfA[][3])
{
    inverseOfA[0][0] = A[1][1] * A[2][2] - A[1][2] * A[2][1];
    inverseOfA[0][1] = A[0][2] * A[2][1] - A[0][1] * A[2][2];
    inverseOfA[0][2] = A[0][1] * A[1][2] - A[0][2] * A[1][1];
    inverseOfA[1][0] = A[1][2] * A[2][0] - A[1][0] * A[2][2];
    inverseOfA[1][1] = A[0][0] * A[2][2] - A[0][2] * A[2][0];
    inverseOfA[1][2] = A[0][2] * A[1][0] - A[0][0] * A[1][2];
    inverseOfA[2][0] = A[1][0] * A[2][1] - A[1][1] * A[2][0];
    inverseOfA[2][1] = A[0][1] * A[2][0] - A[0][0] * A[2][1];
    inverseOfA[2][2] = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    double pro = 1.0 / determinant(A);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            inverseOfA[i][j] *= pro;
        }
    }

    display(inverseOfA);
}

int main()
{
    std::cout << "Enter a11, a12, a13, a21, a22, a23, a31, a32, a33: ";
    double matix[3][3] = {}, inverseMat[3][3] = {};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> matix[i][j];
        }
    }
    inverse(matix, inverseMat);

    return 0;
}