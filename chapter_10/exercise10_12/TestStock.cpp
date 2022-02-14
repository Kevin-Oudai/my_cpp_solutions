#include <iostream>
#include "Stock.h"

int main()
{
    Stock s("MSFT", "Microsoft Corporation");
    s.setCurrentPrice(27.6);
    s.setPreviousClosingPrice(27.5);
    std::cout << "Current Price: " << s.getCurrentPrice() << std::endl;
    std::cout << "Previous Price: " << s.getPreviousClosingPrice() << std::endl;

    std::cout << "Price change percentage: " << s.getChangePercent() << "%." << std::endl;
    return 0;
}