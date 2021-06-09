#include <iostream>

int max(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
        return num2;
}

double max(double num1, double num2)
{
    if (num1 > num2)
        return num1;
    else
        return num2;
}

double max(double num1, double num2, double num3)
{
    return max(max(num1, num2), num3);
}

int main()
{
    std::cout << "The maximum between 3 and 4 is " << max(3, 4) << std::endl;
    std::cout << "The maximum between 3.0 and 5.4 is " << max(3.0, 5.4) << std::endl;
    std::cout << "The maximum between 3.0, 5.4, and 10.14 is "
              << max(3.0, 5.4, 10.14) << std::endl;

    return 0;
}