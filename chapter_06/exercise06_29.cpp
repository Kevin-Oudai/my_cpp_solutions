// Exercise 6.29 - Average of even places

#include <iostream>

double avgOfEvenPlaces(int n);
int reverseNumber(int extract);

double avgOfEvenPlaces(int n)
{
    int count = 1;
    double sum = 0.0, digits = 0;
    n = reverseNumber(n);
    while (n > 0)
    {
        if (count % 2 == 0)
        {
            sum += (n % 10);
            digits++;
        }
        n /= 10;
        count++;
    }
    return (sum / digits);
}

int reverseNumber(int extract)
{
    int reverseNumber = 0;
    while (extract > 0)
    {
        reverseNumber = (reverseNumber * 10) + (extract % 10);
        extract /= 10;
    }
    return reverseNumber;
}

int main()
{
    std::cout << "Enter an integer: ";
    int number;
    std::cin >> number;

    std::cout << "The average of the digits in the even places are: " << avgOfEvenPlaces(number) << std::endl;
    return 0;
}