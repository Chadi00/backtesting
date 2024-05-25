#pragma once
#include <vector>
#include "data_point.hpp"

class DataProvider {
public:
    virtual std::vector<DataPoint> fetchData(const std::string& symbol, const std::string& timeframe) = 0;
    virtual ~DataProvider() = default;
};
