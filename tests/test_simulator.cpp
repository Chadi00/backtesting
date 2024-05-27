#include <iostream>
#include "simulator.hpp"
#include "data_provider.hpp"
#include "simple_moving_average_strategy.hpp"

// Mock DataProvider for testing purposes
class MockDataProviderSimu : public DataProvider {
public:
    std::vector<DataPoint> fetchData(const std::string& symbol, const std::string& startDate, const std::string& endDate) override {
        std::vector<DataPoint> dataPoints = {
            {"2024-05-10", 100, 110, 90, 100, 1000},
            {"2024-05-11", 101, 111, 91, 101, 1100},
            {"2024-05-12", 102, 112, 92, 102, 1200},
            {"2024-05-13", 103, 113, 93, 103, 1300},
            {"2024-05-14", 104, 114, 94, 104, 1400},
            {"2024-05-15", 105, 115, 95, 105, 1500},
            {"2024-05-16", 95, 105, 85, 95, 1600},
            {"2024-05-17", 96, 106, 86, 96, 1700},
            {"2024-05-18", 97, 107, 87, 97, 1800},
            {"2024-05-19", 98, 108, 88, 98, 1900},
            {"2024-05-20", 110, 120, 100, 110, 2000}
        };
        return dataPoints;
    }
};


void testSimulator() {
    MockDataProviderSimu provider;
    SimpleMovingAverageStrategy strategy(5);
    Simulator simulator(provider, strategy, "AAPL", "2024-05-10", "2024-05-20");

    // Run the simulation
    std::cout << "Starting simulator run..." << std::endl;
    simulator.run();
    std::cout << "Simulator run completed." << std::endl;

    // Get the transactions from the strategy
    auto transactions = strategy.getTransactions();

    // Detailed logs for transactions
    if (!transactions.empty()) {
        std::cout << "Simulator test passed.\n";
    }
    else {
        std::cout << "Simulator test failed.\n";
    }

    // Check for specific transaction details
    bool foundTransaction = false;
    for (const auto& transaction : transactions) {
        if (transaction.entryPrice == 95 && transaction.exitPrice == 110) {
            foundTransaction = true;
            break;
        }
    }

    if (foundTransaction) {
        std::cout << "Simulator test validated.\n";
    }
    else {
        std::cout << "Simulator test failed: Expected transaction not found.\n";
    }
}

