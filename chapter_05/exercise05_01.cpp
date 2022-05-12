// Exercise 5.1 - Count positive and negative numbers and compute the average of numbers
#include <iostream>

int main()
{
    int number = 0;
    std::cout << "Enter an integer, the input ends if it is 0: ";
    int positiveCount = 0;
    int negativeCount = 0;
    double total = 0.0;
    do
    {
        std::cin >> number;
        if (number < 0)
            negativeCount++;
        else if (number > 0)
        {
            positiveCount++;
        }
        else
        {
            break;
        }

        total += number;

    } while (number != 0);

    double average = total / (positiveCount + negativeCount);
    if (positiveCount > 0 && negativeCount > 0)
    {
        std::cout << "The number of positives is " << positiveCount << std::endl;
        std::cout << "The number of negatives is " << negativeCount << std::endl;
        std::cout << "The total is " << total << std::endl;
        std::cout << "The average is " << average << std::endl;
    }
    else
        std::cout << "No numbers are entered except 0" << std::endl;
    return 0;
}