#include "order.hpp"
#include <memory>

int main() {

    Order order(
        OrderId{1},
        InstrumentId{2},
        Side::Buy,
        Price{1000},
        Qty{10},
        TimeInForce{5000},
        OrderType::Limit
    );


    std::cout << order << std::endl;

    return 0;
}
