#pragma once
#include <type_traits>
#include <cstdint>
#include <iostream>

template<typename Tag>
struct is_arithmetic_tag : std::false_type {};

struct InstrumentIdTag {};
struct OrderIdTag {};
struct PriceTag {};
struct QtyTag {};
struct TimeInForceTag {};

template<> struct is_arithmetic_tag<PriceTag> : std::true_type {};
template<> struct is_arithmetic_tag<QtyTag> : std::true_type {};


template<typename T, typename Tag>
class StrongType {
public:
	using ValueType = T;
	explicit constexpr StrongType(T value) : value_(value) {}

	constexpr T value() const noexcept {
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

	// operator+
	template<typename U = Tag,
	     std::enable_if_t<is_arithmetic_tag<U>::value, int> = 0>
	constexpr StrongType operator+(const StrongType& rhs) const noexcept
	{
	return StrongType(value_ + rhs.value_);
	}

private:
	T value_;
};


using InstrumentId = StrongType<std::uint32_t, InstrumentIdTag>;
using OrderId = StrongType<std::uint32_t, OrderIdTag>;
using Price = StrongType<std::int64_t, PriceTag>;
using Qty = StrongType<std::uint64_t, QtyTag>;
using TimeInForce = StrongType<std::uint64_t, TimeInForceTag>;




