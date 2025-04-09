#include "StockMarket.h"

StockMarket::StockMarket(const std::string& name, double initialPrice)
    : stockName(name), price(initialPrice) {
    priceHistory.push_back(price);
}

void StockMarket::updatePrice() {
    std::normal_distribution<double> distribution(0.0, 2.0);  // More volatility
    price += distribution(generator);
    if (price < 0.1) price = 0.1;  // Prevent negative prices
    priceHistory.push_back(price);
}

double StockMarket::getPrice() const {
    return price;
}

const std::vector<double>& StockMarket::getPriceHistory() const {
    return priceHistory;
}
