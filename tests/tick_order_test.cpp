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

TEST(PrettyPrint, TickJson) {
    Tick t{Price{100}, Qty{5}, 123456789LL, InstrumentId{42}, /*pad*/};
    std::ostringstream ss; ss << t;
    EXPECT_TRUE(ss.str().rfind("{\"id\":42", 0) == 0);          // starts with id
    EXPECT_NE(ss.str().find("\"qty\":5"), std::string::npos);   // contains qty
    EXPECT_LT(ss.str().size(), 80);
}

