#include <iostream>

template <typename T>

T largest(T x, T y, T z)
{
    if (x > y && x > x)
    {
        return x;
    }
    else if (y > x && y > z)
    {
        return y;
    }
    else
    {
        return z;
    }
}
int main()
{
    std::cout << "The largest of 3 5 7 is " << largest(3, 5, 7) << std::endl;
    std::cout << "The largest of 2.3 4.5 8.7 is " << largest(2.3, 4.5, 8.7) << std::endl;
    std::cout << "The largest of Kevin, Venita, Athena is " << largest("Kevin", "Venita", "Athena") << std::endl;
    return 0;
}