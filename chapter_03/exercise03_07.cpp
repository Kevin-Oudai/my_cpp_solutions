#include <iostream>

int main()
{
    int n1, n2, n3;
    std::cout << "Enter 3 integers: ";
    std::cin >> n1 >> n2 >> n3;

    if (n1 < n2 && n1 < n3)
        std::cout << n2 << " " << n3 << " " << n1 << std::endl;
    else
        std::cout << n1 << " " << n3 << " " << n2 << std::endl;

    return 0;
}