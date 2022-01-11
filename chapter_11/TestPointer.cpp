#include <iostream>

int main()
{
    int count = 5;
    int *pCount = &count;

    std::cout << "The value of count is " << count << std::endl;
    std::cout << "The address of count is " << &count << std::endl;
    std::cout << "The address of count is " << pCount << std::endl;
    std::cout << "The value of count is " << *pCount << std::endl;

    return 0;
}