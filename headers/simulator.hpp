#pragma once
#include "data_provider.hpp"
#include "strategy.hpp"
#include <string>

class Simulator {
private:
    DataProvider& dataProvider;
    Strategy& strategy;
    std::string symbol;
    std::string timeframe;
public:
    Simulator(DataProvider& dp, Strategy& strat, const std::string& sym, const std::string& tf);
    void run();
};
