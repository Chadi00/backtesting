#include <iostream>
#include "data_point.hpp"

void testDataPoint() {
    DataPoint data = { "2024-05-10", 100, 110, 90, 105, 1000 };
    if (data.timestamp == "2024-05-10" && data.open == 100 && data.high == 110 && data.low == 90 && data.close == 105 && data.volume == 1000) {
        std::cout << "DataPoint test passed.\n";
    }
    else {
        std::cout << "DataPoint test failed.\n";
    }
}
