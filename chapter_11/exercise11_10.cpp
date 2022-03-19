#include <iostream>

int *countDigits(const int &number)
{
    int num = number;
    int *dArray = new int[10];
    for (int i = 0; i < 10; i++)
    {
        dArray[i] = 0;
    }

    while (num > 0)
    {
        dArray[num % 10]++;
        num /= 10;
    }
    return dArray;
}

int main()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    int *dArray = countDigits(number);
    for (int i = 0; i < 10; i++)
    {
        std::cout << "count[" << i << "] is " << dArray[i] << std::endl;
    }

    return 0;
}