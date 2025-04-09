#include "Portfolio.h"

Portfolio::Portfolio(double initialCash) : cash(initialCash) {}

void Portfolio::buy(const std::string& stockName, double price, int shares) {
    double cost = price * shares;
    if (cost > cash) return; // Or throw an exception
    cash -= cost;
    stocks[stockName] += shares;
}

void Portfolio::sell(const std::string& stockName, double price, int shares) {
    if (stocks[stockName] < shares) return; // Or throw
    cash += price * shares;
    stocks[stockName] -= shares;
}

double Portfolio::getCash() const { return cash; }
int Portfolio::getShares(const std::string& stockName) const {
    return stocks.at(stockName); // Throws if stock doesn't exist
}
