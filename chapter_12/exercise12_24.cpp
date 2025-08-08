/*
Codex Task: Exercise 12.24 — Solve 3x3 linear equations using Cramer's Rule

Goal
Build a C++17 programme that reads the coefficients of a 3×3 system:
    a11 a12 a13
    a21 a22 a23
    a31 a32 a33
and the right‑hand side vector b1, b2, b3, then solves for x, y, z using Cramer's Rule.

Requirements
- Use double precision (double) and a small tolerance (eps = 1e-9) when testing if a determinant is zero.
- If |A| is effectively zero, print exactly: "No solution".
- Otherwise compute:
    x = |A_x| / |A|
    y = |A_y| / |A|
    z = |A_z| / |A|
  where A_k replaces the k-th column of A with [b1 b2 b3]^T.
- Use camelCase descriptive variable names.
- Keep the code in a single file and include this prompt at the top as a block comment.

Programme structure (suggested)
1) Helper: double det3(double a11, double a12, double a13,
                       double a21, double a22, double a23,
                       double a31, double a32, double a33);
   // Compute 3x3 determinant via rule of Sarrus:
   // a11*(a22*a33 - a23*a32) - a12*(a21*a33 - a23*a31) + a13*(a21*a32 - a22*a31)

2) In main():
   - Prompt and read: a11, a12, a13, a21, a22, a23, a31, a32, a33
   - Prompt and read: b1, b2, b3
   - Compute detA = det3(...)
   - If fabs(detA) < eps → print "No solution" and return 0
   - Compute:
        detAx = det3(b1, a12, a13,  b2, a22, a23,  b3, a32, a33)
        detAy = det3(a11, b1, a13,  a21, b2, a23,  a31, b3, a33)
        detAz = det3(a11, a12, b1,  a21, a22, b2,  a31, a32, b3)
     Then:
        x = detAx / detA
        y = detAy / detA
        z = detAz / detA
   - Print exactly:
        "The solution is " << x << " " << y << " " << z
     (use default formatting; no special rounding required)

I/O example (not to hard‑code)
Input:
  Enter a11, a12, a13, a21, a22, a23, a31, a32, a33:
  1 2 1 0.5 1 0.5 1 4 5
  Enter b1, b2, b3:
  2 5 3
Output:
  No solution
*/

#include <iostream>
#include <cmath>

double det3(double a11, double a12, double a13,
            double a21, double a22, double a23,
            double a31, double a32, double a33)
{
    return a11 * (a22 * a33 - a23 * a32) -
           a12 * (a21 * a33 - a23 * a31) +
           a13 * (a21 * a32 - a22 * a31);
}

int main()
{
    double a11, a12, a13, a21, a22, a23, a31, a32, a33;
    std::cout << "Enter a11, a12, a13, a21, a22, a23, a31, a32, a33:\n";
    std::cin >> a11 >> a12 >> a13 >> a21 >> a22 >> a23 >> a31 >> a32 >> a33;

    double b1, b2, b3;
    std::cout << "Enter b1, b2, b3:\n";
    std::cin >> b1 >> b2 >> b3;

    double detA = det3(a11, a12, a13, a21, a22, a23, a31, a32, a33);
    const double eps = 1e-9;

    if (std::fabs(detA) < eps)
    {
        std::cout << "No solution" << std::endl;
        return 0;
    }

    double detAx = det3(b1, a12, a13,  b2, a22, a23,  b3, a32, a33);
    double detAy = det3(a11, b1, a13,  a21, b2, a23,  a31, b3, a33);
    double detAz = det3(a11, a12, b1,  a21, a22, b2,  a31, a32, b3);

    double x = detAx / detA;
    double y = detAy / detA;
    double z = detAz / detA;

    std::cout << "The solution is " << x << " " << y << " " << z << std::endl;

    return 0;
}

