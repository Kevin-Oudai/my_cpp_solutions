#include "Stock.h"

Stock::Stock(std::string stockSymbol, std::string stockName)
{
    symbol = stockSymbol;
    name = stockName;
    currentPrice = 0;
    previousClosingPrice = 0;
}

std::string Stock::getSymbol() const
{
    return symbol;
}

std::string Stock::getName() const
{
    return name;
}

double Stock::getPreviousClosingPrice() const
{
    return previousClosingPrice;
}

double Stock::getCurrentPrice() const
{
    return currentPrice;
}

void Stock::setPreviousClosingPrice(double cp)
{
    previousClosingPrice = cp;
}

void Stock::setCurrentPrice(double cp)
{
    setPreviousClosingPrice(currentPrice);
    currentPrice = cp;
}

double Stock::getChangePercent()
{
    return ((currentPrice - previousClosingPrice) / currentPrice) * 100;
}