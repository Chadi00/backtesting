#include <iostream>
#include "metrics_calculator.hpp"

void testMetricsCalculator() {
    std::vector<Transaction> transactions = { {100, 110, true}, {120, 115, false} };
    MetricsCalculator calculator(transactions, 1);
    if (calculator.calculateProfit() == 5 && calculator.calculateSuccessRate() == 50) {
        std::cout << "MetricsCalculator test passed.\n";
    }
    else {
        std::cout << "MetricsCalculator test failed.\n";
    }
}
