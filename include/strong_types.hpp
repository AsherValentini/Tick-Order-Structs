#pragma once
#include <type_traits>
#include <cstdint>
#include <iostream>

template<typename T, typename tag>
class StrongType {
public:
	using ValueType = T;
	explicit constexpr StrongType(T value) : value_(value) {}

	constexpr T get() const {
		return value_;
	}

	friend constexpr bool operator==(const StrongType& lhs, const StrongType& rhs) {
		return lhs.value_ == rhs.value_;
	}

	friend constexpr bool operator!=(const StrongType& lhs, const StrongType& rhs) {
		return rhs.value_ != lhs.value_;
	}

	friend constexpr std::ostream& operator<<(std::ostream& os, const StrongType& type) {
		os << type.value_;
		return os;
	}

private:
	T value_;
};

struct InstrumentIdTag {};
struct OrderIdTag {};
struct PriceTag {};
struct QtyTag {};
struct TimeInForceTag {};


using InstrumentId = StrongType<std::uint32_t, InstrumentIdTag>;
using OrderId = StrongType<std::uint32_t, OrderIdTag>;
using Price = StrongType<std::int64_t, PriceTag>;
using Qty = StrongType<std::uint64_t, QtyTag>;
using TimeInForce = StrongType<std::uint64_t, TimeInForceTag>;




