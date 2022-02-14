#ifndef STOCK_H
#define STOCK_H
#include <string>

class Stock
{
public:
    Stock(std::string stockSymbol, std::string stockName);
    std::string getSymbol() const;
    std::string getName() const;
    double getPreviousClosingPrice() const;
    double getCurrentPrice() const;
    void setPreviousClosingPrice(double cp);
    void setCurrentPrice(double cp);
    double getChangePercent();

private:
    std::string symbol;
    std::string name;
    double previousClosingPrice;
    double currentPrice;
};
#endif