#pragma once
#include "data_point.hpp"
#include <vector>

struct Transaction {
    double entryPrice;
    double exitPrice;
    bool success;
};

class Strategy {
public:
    virtual void onTick(const DataPoint& data) = 0;
    virtual void onEnd() = 0;
    virtual std::vector<Transaction> getTransactions() const = 0;
    virtual ~Strategy() = default;
};
