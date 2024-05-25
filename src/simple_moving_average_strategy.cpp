#include "simple_moving_average_strategy.hpp"

SimpleMovingAverageStrategy::SimpleMovingAverageStrategy(int period) : period(period) {}

void SimpleMovingAverageStrategy::onTick(const DataPoint& data) {
    prices.push_back(data.close);
    if (prices.size() > period) {
        prices.pop_front();
    }

    if (prices.size() == period) {
        double avg = movingAverage();
        // Example buy/sell logic based on moving average
        if (data.close > avg) {
            // Buy signal
            transactions.push_back({ data.close, 0, false }); // Placeholder for entry price
        }
        else if (!transactions.empty() && transactions.back().exitPrice == 0) {
            // Sell signal
            transactions.back().exitPrice = data.close;
            transactions.back().success = (transactions.back().entryPrice < transactions.back().exitPrice);
        }
    }
}

void SimpleMovingAverageStrategy::onEnd() {
    // Close any open positions at the end of the simulation
    if (!transactions.empty() && transactions.back().exitPrice == 0) {
        transactions.back().exitPrice = prices.back();
        transactions.back().success = (transactions.back().entryPrice < transactions.back().exitPrice);
    }
}

std::vector<Transaction> SimpleMovingAverageStrategy::getTransactions() const {
    return transactions;
}

double SimpleMovingAverageStrategy::movingAverage() const {
    double sum = 0;
    for (double price : prices) {
        sum += price;
    }
    return sum / prices.size();
}
