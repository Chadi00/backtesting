#include <iostream>
#include "strategy.hpp"

class MockStrategy : public Strategy {
public:
    void onTick(const DataPoint& data) override {}
    void onEnd() override {}
    std::vector<Transaction> getTransactions() const override {
        return {};
    }
};

void testStrategy() {
    MockStrategy strategy;
    if (strategy.getTransactions().empty()) {
        std::cout << "Strategy test passed.\n";
    }
    else {
        std::cout << "Strategy test failed.\n";
    }
}
