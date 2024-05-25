#pragma once
#include <vector>
#include "strategy.hpp"

class MetricsCalculator {
private:
    std::vector<Transaction> transactions;
public:
    MetricsCalculator(const std::vector<Transaction>& trans);
    double calculateProfit() const;
    double calculateSuccessRate() const;
};
