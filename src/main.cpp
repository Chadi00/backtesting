#include <iostream>
#include "polygon_data_provider.hpp"
#include "simple_moving_average_strategy.hpp"
#include "simulator.hpp"
#include "metrics_calculator.hpp"

int main() {
    double trx_cost = 1;
    PolygonDataProvider provider;
    SimpleMovingAverageStrategy strategy(5);
    Simulator simulator(provider, strategy, "AAPL", "2024-03-01", "2024-05-29");
    simulator.run();
    std::vector<Transaction> trx = strategy.getTransactions();
    MetricsCalculator metrics(trx, trx_cost);
    std::cout << "\nProfit = " << metrics.calculateProfit();
    std::cout << "\nSuccess rate = " << metrics.calculateSuccessRate();
    return 0;
}
