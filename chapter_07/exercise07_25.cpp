// Exercise 7.25 - Game: Sum of even or odd faces

#include <iostream>
#include <cstdlib>
#include <ctime>

int faceSum(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}

bool isAllEven(int num1, int num2, int num3)
{
    if ((num1 % 2 == 0) && (num2 % 2 == 0) && (num3 % 2 == 0))
    {
        return true;
    }
    return false;
}

bool isAllOdd(int num1, int num2, int num3)
{
    if ((num1 % 2 == 1) && (num2 % 2 == 1) && (num3 % 2 == 1))
    {
        return true;
    }
    return false;
}

int maxNum(int num1, int num2, int num3)
{
    int max = num1;
    if (num2 > max)
        max = num2;
    if (num3 > max)
        return num3;
    return max;
}

int main()
{
    srand(time(0));
    int num1 = rand() % 6 + 1;
    int num2 = rand() % 6 + 1;
    int num3 = rand() % 6 + 1;
    if (isAllEven(num1, num2, num3))
    {
        std::cout << "The sum of the even faces is: " << faceSum(num1, num2, num3) << std::endl;
    }
    else if (isAllOdd(num1, num2, num3))
    {
        std::cout << "The sum of the odd faces is: " << faceSum(num1, num2, num3) << std::endl;
    }
    else
    {
        std::cout << "The largest of the three numbers is: " << maxNum(num1, num2, num3) << std::endl;
    }

    return 0;
}