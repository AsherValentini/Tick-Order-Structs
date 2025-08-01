#pragma once
#include <iostream>
#include <cstdint>
#include "strong_types.hpp"

struct Tick {
	InstrumentId id;
	std::int64_t ts_ns;
	Price px;
	Qty qty;

	Tick (InstrumentId i, std::int64_t t, Price p, Qty q)
		: id(i), ts_ns(t), px(p), qty(q) {}

	static_assert(sizeof(Tick) <= 32, "Tick too large");
};


inline std::ostream& operator<<(std::ostream& os, const Tick& tick) {
	os << "[Tick]";
	os << " instrument: " << tick.id;
	os << " time: " << tick.ts_ns;
	os << " price: " << tick.px;
	os << " quantity: " << tick.qty;
	return os;
}