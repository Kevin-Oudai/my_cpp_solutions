#include <iostream>

// Swap two variables using pass-by-value
void swap1(int n1, int n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

// Swap two variables using pass-by-reference
void swap2(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

// Pass two pointers by value
void swap3(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Pass two pointer by reference
void swap4(int *&p1, int *&p2)
{
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    // Declare and initialize variables
    int num1 = 1;
    int num2 = 2;

    std::cout << "Before invoking the swap function, num1 is "
              << num1 << " and num2 is " << num2 << std::endl;

    // Invoke the swap function to attempt to swap two variables
    swap1(num1, num2);

    std::cout << "After invoking the swap function, num1 is " << num1
              << " and num2 is " << num2 << std::endl;
    std::cout << "Before invoking the swap funciton, num1 is "
              << num1 << " and num2 is " << num2 << std::endl;

    // Invoke the swap funciton to attempt to swap two variables
    swap2(num1, num2);
    std::cout << "After invoking the swap function, num1 is " << num1
              << " and num2 is " << num2 << std::endl;
    std::cout << "Before invoking the swap function, num1 is " << num1
              << " and num2 is " << num2 << std::endl;

    // Invoke the swap function to attempt to swap two variables
    swap3(&num1, &num2);
    std::cout << "After invoking the swap function, num1 is " << num1
              << " and num2 is " << num2 << std::endl;

    int *p1 = &num1;
    int *p2 = &num2;

    std::cout << "Before invoking the swap function, p1 is "
              << p1 << " and p2 is " << p2 << std::endl;

    // Invoke the swap function to attempt to swap two variables
    swap4(p1, p2);
    std::cout << "After invoking the swap function, p1 is " << p1
              << " and p2 is " << p2 << std::endl;

    return 0;
}