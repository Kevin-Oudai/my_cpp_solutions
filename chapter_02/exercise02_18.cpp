#include <iostream>
#include <cmath>

int main()
{
    std::cout << "x\ty\tpow(x, y)" << std::endl;
    std::cout << "2.5\t1.2\t" << pow(2.5, 1.2) << std::endl;
    std::cout << "5.0\t2.4\t" << pow(5.0, 2.4) << std::endl;
    std::cout << "1.2\t3.6\t" << pow(1.2, 3.6) << std::endl;
    std::cout << "2.4\t5.0\t" << pow(2.4, 5.0) << std::endl;
    std::cout << "3.6\t2.5\t" << pow(3.6, 2.5) << std::endl;
    return 0;
}