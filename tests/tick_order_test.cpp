#include "core/tick.hpp"
#include "core/order.hpp"
#include <gtest/gtest.h>

TEST(SizeChecks, StructByteSizes) {
    static_assert(sizeof(Tick)  == 32);
    static_assert(sizeof(Order) == 40);
    SUCCEED();
}

TEST(StrongTypes, Addition) {
    Price  p1{10}, p2{15};
    EXPECT_EQ((p1 + p2).value(), 25);
}

