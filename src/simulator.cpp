#include "simulator.hpp"
#include "data_point.hpp"
#include <iostream>

Simulator::Simulator(DataProvider& provider, Strategy& strategy, const std::string& symbol, const std::string& startDate, const std::string& endDate)
    : provider(provider), strategy(strategy), symbol(symbol), startDate(startDate), endDate(endDate) {}

void Simulator::run() {
    std::cout << "Fetching data for symbol: " << symbol << " from " << startDate << " to " << endDate << std::endl;
    auto dataPoints = provider.fetchData(symbol, startDate, endDate);
    std::cout << "Data fetched: " << dataPoints.size() << " points" << std::endl;

    for (const auto& dataPoint : dataPoints) {
        std::cout << "Processing data point: " << dataPoint.timestamp << ", Close: " << dataPoint.close << std::endl;
        strategy.onTick(dataPoint);
    }
    strategy.onEnd();
}
