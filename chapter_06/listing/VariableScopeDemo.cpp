// Listing 6.11

#include <iostream>

void t1();
void t2();

int main()
{
    t1();
    t2();

    return 0;
}

int y;

void t1()
{
    int x = 1;
    std::cout << "x is " << x << std::endl;
    std::cout << "y is " << y << std::endl;
    x++;
    y++;
}

void t2()
{
    int x = 1;
    std::cout << "x is " << x << std::endl;
    std::cout << "y is " << y << std::endl;
}