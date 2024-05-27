#include "simple_moving_average_strategy.hpp"
#include <numeric>
#include <iostream>

SimpleMovingAverageStrategy::SimpleMovingAverageStrategy(int period) : period(period) {}

double SimpleMovingAverageStrategy::movingAverage() const {
    if (prices.size() < period) return 0.0;
    return std::accumulate(prices.begin(), prices.end(), 0.0) / period;
}

void SimpleMovingAverageStrategy::onTick(const DataPoint& data) {
    prices.push_back(data.close);
    if (prices.size() > period) {
        prices.pop_front();
    }

    if (prices.size() == period) {
        double avg = movingAverage();
        std::cout << "Price: " << data.close << ", Moving Average: " << avg << std::endl;

        // Check for active trade
        if (!transactions.empty() && transactions.back().exitPrice == 0) {
            // Exit condition: price crosses above moving average
            if (data.close > avg) {
                transactions.back().exitPrice = data.close;
                transactions.back().success = data.close > transactions.back().entryPrice;
                std::cout << "Exiting trade: Entry Price: " << transactions.back().entryPrice << ", Exit Price: " << data.close << std::endl;
            }
        }
        else {
            // Entry condition: price crosses below moving average
            if (data.close < avg) {
                transactions.push_back({ data.close, 0.0, false });
                std::cout << "Entering trade at price: " << data.close << std::endl;
            }
        }
    }
}

void SimpleMovingAverageStrategy::onEnd() {
    if (!transactions.empty() && transactions.back().exitPrice == 0) {
        transactions.back().exitPrice = prices.back();
        transactions.back().success = transactions.back().exitPrice > transactions.back().entryPrice;
        std::cout << "Finalizing trade: Entry Price: " << transactions.back().entryPrice << ", Exit Price: " << transactions.back().exitPrice << std::endl;
    }
}

std::vector<Transaction> SimpleMovingAverageStrategy::getTransactions() const {
    return transactions;
}
