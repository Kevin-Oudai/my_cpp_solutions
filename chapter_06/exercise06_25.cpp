#include <iostream>
#include <iomanip>

bool isPrime(int num)
{
    if (num == 2 || num == 3)
    {
        return true;
    }

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int sumPrime(int num)
{
    int primeSum = 0;
    while (num > 0)
    {
        primeSum += (num % 10);
        num /= 10;
    }
    return primeSum;
}

int main()
{
    int count = 0;
    int num = 2;
    std::cout << std::setw(12) << "Prime Number\t" << std::setw(17) << "Sum of its digits" << std::endl;
    while (count < 25)
    {
        if (isPrime(num) && isPrime(sumPrime(num)))
        {
            std::cout << std::left << std::setw(12) << num << "\t" << std::left << std::setw(17) << sumPrime(num) << std::endl;
            count++;
        }
        num++;
    }

    return 0;
}