// Exercise 7.7 - Sum of Even random numbers

#include <iostream>
#include <ctime>
#include <cstdlib>

int sumArray(int numbers[], int SIZE, int &total)
{
    for (int i = 0; i < SIZE; i++)
    {
        total += numbers[i];
    }
    return total;
}

int main()
{
    srand(time(0));
    int numbers[25], count = 0, number = 0, total = 0;
    while (count < 25)
    {
        number = rand() % 26;
        if (number % 2 == 0)
        {
            numbers[count] = number;
            count++;
        }
    }

    sumArray(numbers, 25, total);
    std::cout << "The total of the array is: " << total << std::endl;
    return 0;
}