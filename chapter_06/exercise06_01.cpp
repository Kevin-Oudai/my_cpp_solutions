// Exercise 6.1 - Math: Triangular Numbers
#include <iostream>

int getTriangularNumber(int n)
{
    int answer = n * (n + 1) / 2;
    return answer;
}

int main()
{
    for (int i = 1; i <= 75; i++)
    {
        std::cout << getTriangularNumber(i);
        (i % 5 == 0) ? std::cout << std::endl : std::cout << " ";
    }
    return 0;
}