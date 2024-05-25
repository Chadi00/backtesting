#include "metrics_calculator.hpp"

MetricsCalculator::MetricsCalculator(const std::vector<Transaction>& trans)
    : transactions(trans) {}

double MetricsCalculator::calculateProfit() const {
    double totalProfit = 0;
    for (const auto& transaction : transactions) {
        totalProfit += (transaction.exitPrice - transaction.entryPrice);
    }
    return totalProfit;
}

double MetricsCalculator::calculateSuccessRate() const {
    int successfulTrades = 0;
    for (const auto& transaction : transactions) {
        if (transaction.success) {
            successfulTrades++;
        }
    }
    return static_cast<double>(successfulTrades) / transactions.size() * 100;
}
