#include <iostream>

void displayArray(bool results[])
{
    for (int j = 1; j <= 9; j++)
    {
        (results[j - 1]) ? std::cout << "T " : std::cout << "F ";
        if (j % 3 == 0)
        {
            std::cout << std::endl;
        }
    }
}

void reverseArray(bool results[])
{
    bool temp;
    for (int j = 0; j < 5; j++)
    {
        temp = results[j];
        results[j] = results[8 - j];
        results[8 - j] = temp;
    }
    displayArray(results);
}

void fillArray(int number, bool results[])
{
    for (int i = 0; i <= 9; i++)
    {
        results[i] = number % 2;
        number /= 2;
    }
    reverseArray(results);
}

int main()
{
    bool results[9] = {0};
    int number;
    std::cout << "Enter a number between 0 and 511: ";
    std::cin >> number;
    fillArray(number, results);
    return 0;
}