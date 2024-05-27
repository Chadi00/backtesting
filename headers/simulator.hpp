#pragma once
#include "data_provider.hpp"
#include "strategy.hpp"
#include <string>

class Simulator {
public:
    Simulator(DataProvider& provider, Strategy& strategy, const std::string& symbol, const std::string& startDate, const std::string& endDate);
    void run();
private:
    DataProvider& provider;
    Strategy& strategy;
    std::string symbol;
    std::string startDate;
    std::string endDate;
};
