#pragma once
#include <vector>
#include <string>
#include "data_point.hpp"

class DataProvider {
public:
    virtual ~DataProvider() = default;
    virtual std::vector<DataPoint> fetchData(const std::string& symbol, const std::string& startDate, const std::string& endDate) = 0;
};
