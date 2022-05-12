// Exercise 5.47 - Statistics: Compute mean and standard deviation

#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Enter ten numbers: ";
    int count = 0;
    double num, sum = 0.0, squareSum, sumSquare = 0, mean, deviation;
    while (count < 10)
    {
        std::cin >> num;
        sum += num;
        sumSquare += std::pow(num, 2);
        count++;
    }

    mean = sum / 10.0;
    squareSum = std::pow(sum, 2);
    deviation = std::sqrt((sumSquare - (squareSum / 10)) / 9);
    std::cout << "The mean is " << mean << std::endl;
    std::cout << "The standard deviation is " << deviation << std::endl;
    return 0;
}