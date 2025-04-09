#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <string>
#include <unordered_map>

class Portfolio {
public:
    Portfolio(double initialCash);
    void buy(const std::string& stockName, double price, int shares);
    void sell(const std::string& stockName, double price, int shares);
    double getCash() const;
    int getShares(const std::string& stockName) const;

private:
    double cash;
    std::unordered_map<std::string, int> stocks; // Maps stock names to shares
};

#endif // PORTFOLIO_H
