#include "simulator.hpp"

Simulator::Simulator(DataProvider& dp, Strategy& strat, const std::string& sym, const std::string& tf)
    : dataProvider(dp), strategy(strat), symbol(sym), timeframe(tf) {}

void Simulator::run() {
    auto data = dataProvider.fetchData(symbol, timeframe);
    for (const auto& dp : data) {
        strategy.onTick(dp);
    }
    strategy.onEnd();
}
