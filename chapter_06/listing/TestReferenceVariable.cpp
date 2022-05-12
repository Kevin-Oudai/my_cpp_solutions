// Listing 6.15

#include <iostream>

int main()
{
    int count = 1;
    int &r = count;
    std::cout << "count is " << count << std::endl;
    std::cout << "r is " << r << std::endl;

    r++;
    std::cout << "count is " << count << std::endl;
    std::cout << "r is " << r << std::endl;

    count = 10;
    std::cout << "count is " << count << std::endl;
    std::cout << "r is " << r << std::endl;

    return 0;
}