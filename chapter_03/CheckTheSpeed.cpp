#include <iostream>

int main()
{
    double speed;
    std::cout << "Enter the speed: ";
    std::cin >> speed;

    if (speed < 20)
        std::cout << "too slow" << std::endl;
    else if (speed > 80)
        std::cout << "too fast" << std::endl;
    else
        std::cout << "just right" << std::endl;

    return 0;
}