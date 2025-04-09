#ifndef STOCKMARKET_H
#define STOCKMARKET_H

#include <vector>
#include <random>
#include <string>

class StockMarket {
private:
    std::string stockName;
    double price;
    std::vector<double> priceHistory;
    std::default_random_engine generator;

public:
    StockMarket(const std::string& name, double initialPrice);

    void updatePrice();
    double getPrice() const;
    const std::vector<double>& getPriceHistory() const;
};

#endif // STOCKMARKET_H
