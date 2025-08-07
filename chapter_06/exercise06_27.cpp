// Exercise 6.27 - Math: approximate the square root
#include <iostream>

double sqrt(int n)
{
    double nextGuess = 1, lastGuess;
    do
    {
        lastGuess = nextGuess;
        nextGuess = (lastGuess + (n / lastGuess)) / 2.0;
    } while (abs(nextGuess * 10000 - lastGuess * 10000) > 1);
    return nextGuess;
}

int main()
{
    std::cout << "The square root of 4 is: " << sqrt(4) << std::endl;
    return 0;
}