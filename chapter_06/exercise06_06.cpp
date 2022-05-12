// Exercise 6.6 - Display patterns

#include <iostream>

void displayPattern(int n)
{
    for (int i = n; i > 1; i -= 2)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}
int main()
{
    displayPattern(16);
    return 0;
}