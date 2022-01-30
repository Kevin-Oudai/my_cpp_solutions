#include <iostream>

int main()
{
    std::cout << "Pi is approximately: "
              << 4.0 * (1.0 - 1.0 / 3 + 1.0 / 5 - 1.0 / 7 + 1.0 / 9 - 1.0 / 11) << std::endl;
    std::cout << "Pi is approximately: "
              << 4.0 * (1.0 - 1.0 / 3 + 1.0 / 5 - 1.0 / 7 + 1.0 / 9 - 1.0 / 11 + 1.0 / 13) << std::endl;
    return 0;
}