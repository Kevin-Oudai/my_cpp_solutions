// Exercise 6.10 - Financial Application: Find the profit-per-item

#include <iostream>
#include <iomanip>

double computeProfitPerItem(double quantity)
{
    double profit;
    if (quantity <= 1000 && quantity >= 0)
    {
        profit = quantity;
    }
    else if (quantity <= 5000)
    {
        profit = 1000;
        profit += ((quantity - 1000) * 2);
    }
    else if (quantity > 5000)
    {
        profit = 1000;
        profit += (4000 * 2);
        profit += ((quantity - 5000) * 5);
    }
    else
    {
        profit = 0;
    }
    return profit;
}

int main()
{
    std::cout << std::setw(11) << std::left << "Quantity"
              << std::setw(22) << "Profit-per-item (in $)" << std::endl;
    for (int i = 1000; i <= 10000; i += 1000)
    {
        std::cout << std::setw(11) << std::left << i
                  << std::setw(22) << computeProfitPerItem(i) << std::endl;
    }
    return 0;
}