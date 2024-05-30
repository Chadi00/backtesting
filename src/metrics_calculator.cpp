#include "metrics_calculator.hpp"

MetricsCalculator::MetricsCalculator(const std::vector<Transaction>& trans, const double trx_cost)
    : transactions(trans), trx_cost(trx_cost) {}

double MetricsCalculator::calculateProfit() const {
    double totalProfit = 0;
    double totalCost = 0;
    for (const auto& transaction : transactions) {
        totalProfit += (transaction.exitPrice - transaction.entryPrice);
        totalCost += trx_cost;
    }
    return totalProfit - totalCost;
}

double MetricsCalculator::calculateSuccessRate() const {
    int successfulTrades = 0;
    for (const auto& transaction : transactions) {
        if (transaction.success) {
            successfulTrades++;
        }
    }
    if (successfulTrades == 0) {
        return 0;
    }
    return static_cast<double>(successfulTrades) / transactions.size() * 100;
}


