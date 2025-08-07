// Exercise 7.5 - Print distinct numbers

#include <iostream>

void displayNumbers(int numbers[])
{
    std::cout << "The distinct numbers are: ";
    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] == 0)
        {
            break;
        }
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

bool numberInNumbers(int numbers[], int number)
{

    for (int i = 0; i < 10; i++)
    {
        if (number == numbers[i])
        {
            return true;
        }
    }
    return false;
}

void initializeList(int integers[])
{
    for (int i = 0; i < 10; i++)
    {
        integers[i] = 0;
    }
}

int main()
{
    int numbers[10], number, count = 0;
    initializeList(numbers);
    std::cout << "Enter ten numbers: ";
    for (int i = 0; i < 10; i++)
    {
        std::cin >> number;
        if (numberInNumbers(numbers, number))
            continue;
        else
        {
            numbers[count] = number;
            count++;
        }
    }
    displayNumbers(numbers);
}