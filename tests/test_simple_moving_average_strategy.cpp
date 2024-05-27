#include <iostream>
#include "simple_moving_average_strategy.hpp"
#include "data_point.hpp"

// Function to simulate a sequence of data points with varying prices
std::vector<DataPoint> generateSampleData() {
    return {
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
}

void testSimpleMovingAverageStrategy() {
    std::cout << "\n------------- Starting Simple Moving Average Strategy TEST ------------- \n";


    SimpleMovingAverageStrategy strategy(5);
    auto sampleData = generateSampleData();

    for (const auto& data : sampleData) {
        strategy.onTick(data);
    }

    strategy.onEnd();

    auto transactions = strategy.getTransactions();
    if (!transactions.empty()) {
        std::cout << "SimpleMovingAverageStrategy test passed.\n";
    }
    else {
        std::cout << "SimpleMovingAverageStrategy test failed.\n";
    }
    std::cout << "------------- Ended Simple Moving Average Strategy TEST ------------- \n \n";
}
