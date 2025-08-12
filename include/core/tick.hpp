#pragma once
#include <cstdint>
#include <type_traits>
#include "core/strong_types.hpp"

struct Tick {
	Price px; // 8 B
	Qty qty; // 8 B
	std::int64_t ts_ns; // 8 B
	InstrumentId id; // 4 B
    	std::uint32_t _pad{0}; // 4  ← explicit tail padding
};

static_assert(sizeof(Tick) <= 32, "Tick too large");
static_assert(std::is_trivially_copyable_v<Tick>);

inline std::ostream& operator<<(std::ostream& os, const Tick& t) {
    return os << R"({"id":)"  << t.id
              << R"(,"ts":)" << t.ts_ns
              << R"(,"px":)" << t.px
              << R"(,"qty":)"<< t.qty
              << '}';
}
