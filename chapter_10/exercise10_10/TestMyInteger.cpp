#include <iostream>
#include "MyInteger.h"

int main()
{
    MyInteger a(4);
    std::cout << "Integer is: " << a.getInteger() << std::endl;
    std::cout << a.getInteger() << " is even? " << (a.isEven() ? "Yes" : "No") << std::endl;
    std::cout << a.getInteger() << " is odd? " << (a.isOdd() ? "Yes" : "No") << std::endl;
    std::cout << a.getInteger() << " is prime? " << (a.isPrime() ? "Yes" : "No") << std::endl;
    std::cout << a.getInteger() << " is equal to 12? " << (a.equals(12) ? "Yes" : "No") << std::endl;
    std::cout << "15 to an integer: " << a.parseInt("15") << std::endl;
    return 0;
}