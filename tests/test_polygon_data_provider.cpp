#include <iostream>
#include "polygon_data_provider.hpp"

void testPolygonDataProvider() {
    PolygonDataProvider provider;
    auto data = provider.fetchData("AAPL", "2024-05-10", "2024-05-20");

    if (!data.empty() && data[0].close == 183.05) {
        std::cout << "PolygonDataProvider test passed.\n";
    }
    else {
        std::cout << "PolygonDataProvider test failed.\n";
    }
}
