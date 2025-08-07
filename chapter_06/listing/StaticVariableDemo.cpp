// Listing 6.12

#include <iostream>

void t1();

int main()
{
    t1();
    t1();

    return 0;
}

void t1()
{
    static int x = 1;
    int y = 1;
    x++;
    y++;
    std::cout << "x is " << x << std::endl;
    std::cout << "y is " << y << std::endl;
}