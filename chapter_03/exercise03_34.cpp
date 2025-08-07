#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    int x1, y1, x2, y2;
    srand(time(0));

    x1 = rand() % 300 - 150;
    y1 = rand() % 300 - 150;
    x2 = rand() % 300 - 150;
    y2 = rand() % 300 - 150;

    std::cout << "The two points are: (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")." << std::endl;
    return 0;
}