#include <iostream>
#include <iomanip>
#include "MyInteger.h"
#include "StackOfIntegers.h"

int main()
{
    StackOfIntegers result;
    int num = 2;
    while (num < 100)
    {
        MyInteger a(num);
        if (!a.isPrime())
        {
            result.push(a.getInteger());
                }
        num++;
    }
    int count = 1;
    while (!result.isEmpty())
    {
        std::cout << result.pop() << " ";
        count++;
    }
    return 0;
}