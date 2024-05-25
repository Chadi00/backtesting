#pragma once
#include <string>

struct DataPoint {
    std::string timestamp;
    double open;
    double high;
    double low;
    double close;
    double volume;
};
