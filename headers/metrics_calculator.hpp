#pragma once
#include <vector>
#include "strategy.hpp"

class MetricsCalculator {
private:
    std::vector<Transaction> transactions;
    double trx_cost;
public:
    MetricsCalculator(const std::vector<Transaction>& trans, const double trx_cost);
    double calculateProfit() const;
    double calculateSuccessRate() const;
};
