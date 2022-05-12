// Exercise 6.2 - Average of digits in an integer

#include <iostream>

double averageDigits(long n)
{
    double sum = 0;
    int count = 0;
    while (n > 0)
    {
        sum += (n % 10);
        n /= 10;
        count++;
    }
    double average = sum * 1.0 / count;
    return average;
}

int main()
{
    (averageDigits(936) == 6.0) ? std::cout << "The function works\n" : std::cout << "The function has an error\n";
    return 0;
}