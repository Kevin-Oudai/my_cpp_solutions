#include <iostream>

inline void f(int month, int year)
{
    std::cout << "month is " << month << std::endl;
    std::cout << "year is " << year << std::endl;
}

int main()
{
    int month = 10, year = 2008;
    f(month, year);
    f(9, 2010);

    return 0;
}