#include <iostream>

void swap(int &n1, int &n2)
{
    std::cout << "\tInside the swap function" << std::endl;
    std::cout << "\tBefore swapping n1 is " << n1 << " n2 is "
              << n2 << std::endl;

    int temp = n1;
    n1 = n2;
    n2 = temp;

    std::cout << "\tAfter swapping n1 is " << n1 << " n2 is "
              << n2 << std::endl;
}

int main()
{
    int num1 = 1;
    int num2 = 2;

    std::cout << "Before invoking the swap function, num1 is " << num1
              << " and num2 is " << num2 << std::endl;

    swap(num1, num2);

    std::cout << "After invoking the swap function, num1 is " << num1
              << " and num2 is " << num2 << std::endl;

    return 0;
}