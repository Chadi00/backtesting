#include <iostream>
#include "data_point.hpp"

int main() {
    DataPoint data;
    data.open = 10.23;
    std::cout << data.open;

    return 0;
}
