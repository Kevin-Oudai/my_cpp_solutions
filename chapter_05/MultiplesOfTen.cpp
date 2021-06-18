// Exercise 5.29 - Display multiples of 10
#include <iostream>

int main()
{
    int count = 1;
    for (int i = 4000; i <= 4500; i += 10)
    {
        (count % 15 == 0) ? std::cout << i << std::endl : std::cout << i << " ";
        count++;
    }
    return 0;
}