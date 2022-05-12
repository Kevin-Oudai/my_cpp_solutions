// Exercise 5.39 - Financial Application: Find the profit-per-item

#include <iostream>

int main()
{
    int items = 0;
    double profit = 0;
    do
    {
        items++;
        if (items <= 1000)
        {
            profit = items;
        }
        else if (items <= 5000)
        {
            profit = 1000;
            profit += ((items - 1000) * 2);
        }
        else if (items > 5000)
        {
            profit = 1000;
            profit += (4000 * 2);
            profit += ((items - 5000) * 5);
        }
        else
            std::cout << "something wonky because it has no input." << std::endl;

    } while (profit < 50000);
    std::cout << "You need " << items << " items to make a profit of " << profit << std::endl;
    return 0;
}