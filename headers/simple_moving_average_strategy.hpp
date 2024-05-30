#pragma once
#include "strategy.hpp"
#include <deque>
#include <vector>

class SimpleMovingAverageStrategy : public Strategy {
private:
    int period;
    std::deque<double> prices;
    std::vector<Transaction> transactions;
    
public:
    SimpleMovingAverageStrategy(int period);
    double movingAverage() const;
    void onTick(const DataPoint& data) override;
    void onEnd() override;
    std::vector<Transaction> getTransactions() const override;
};


