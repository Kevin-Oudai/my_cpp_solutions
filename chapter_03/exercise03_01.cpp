#include <iostream>
#include <cmath>

int main()
{
    double a, b, c, root1, root2, determinant;
    std::cout << "Enter a, b, c: ";
    std::cin >> a >> b >> c;

    determinant = pow(b, 2) - 4 * a * c;
    if (determinant > 0)
    {
        root1 = (-b + pow(determinant, 0.5)) / (2 * a);
        root2 = (-b - pow(determinant, 0.5)) / (2 * a);

        std::cout << "The roots are " << root1 << " and " << root2 << std::endl;
    }
    else if (determinant == 0)
    {
        root1 = (-b + pow(determinant, 0.5)) / (2 * a);

        std::cout << "The root is " << root1 << std::endl;
    }
    else
    {
        std::cout << "The equation has no real roots" << std::endl;
    }

    return 0;
}