#include <iostream>

void countDigits(const int &number, int dArray[], int size)
{
    int num = number;
    while (num > 0)
    {
        dArray[num % 10]++;
        num /= 10;
    }
}

int main()
{
    int number, dArray[10] = {}, size = 10;
    std::cout << "Enter a number: ";
    std::cin >> number;

    countDigits(number, dArray, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << i << " has a count of " << dArray[i] << std::endl;
    }

    return 0;
}