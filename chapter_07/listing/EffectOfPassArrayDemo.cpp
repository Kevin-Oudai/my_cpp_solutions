// Listing 7.5 - EffectOfPassArrayDemo.cpp

#include <iostream>

void m(int, int[]);

int main()
{
    int x = 1;
    int y[10];
    y[0] = 1;

    m(x, y);

    std::cout << "x is " << x << std::endl;
    std::cout << "y[0] is " << y[0] << std::endl;

    return 0;
}

void m(int number, int numbers[])
{
    number = 1001;
    numbers[0] = 5555;
}