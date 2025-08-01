#include "tick.hpp"

int main() {
    Tick tick{InstrumentId{2},
              5000,
              Price{10},
              Qty{1}};

    std::cout << tick << std::endl;
    return 0;
}

