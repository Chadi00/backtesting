#include <iostream>
#include "polygon_data_provider.hpp"
#include "simple_moving_average_strategy.hpp"
#include "simulator.hpp"
#include "metrics_calculator.hpp"

int main() {
    PolygonDataProvider dataProvider;
    SimpleMovingAverageStrategy strategy(14);
    Simulator simulator(dataProvider, strategy, "AAPL", "1D");
    simulator.run();

    auto transactions = strategy.getTransactions();
    MetricsCalculator metrics(transactions);
    std::cout << "Profit: " << metrics.calculateProfit() << std::endl;
    std::cout << "Success Rate: " << metrics.calculateSuccessRate() << "%" << std::endl;

    return 0;
}
