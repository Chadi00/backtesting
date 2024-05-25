#pragma once
#include "data_provider.hpp"
#include <vector>
#include <string>

class PolygonDataProvider : public DataProvider {
public:
    std::vector<DataPoint> fetchData(const std::string& symbol, const std::string& timeframe) override;
};
