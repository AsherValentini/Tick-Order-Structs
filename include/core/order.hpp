#pragma once
#include <cstdint>
#include <type_traits>
#include "core/strong_types.hpp"

enum class Side : uint8_t {
	Buy,
	Sell,
	Count // <- not a real side, just locks the enums length
};
static_assert(static_cast<std::uint8_t>(Side::Count) == 2,
	"Side enum count changed-update code that depends on it");

enum class OrderType : uint8_t {
	Limit,
	Market,
	Count
};

static_assert(static_cast<std::uint8_t>(OrderType::Count) ==2,
	"OrderType count changed-update code that depends on it");

struct Order {
	Price px; // 8 B
	Qty qty; // 8 B
	TimeInForce tif; // 8 B
	OrderId oid; // 4 B
	InstrumentId iid; // 4 B
	OrderType type; // 1 B
	Side side; // 1 B

	std::uint8_t flags{0};   // 1  (IOC, PostOnly, etc.)
	std::uint8_t venue{0};   // 1
	std::uint32_t _pad{0};   // 4  ← makes total exactly 40 B

};

static_assert(sizeof(Order) == 40, "Order should be exactly 40 bytes");
static_assert(std::is_trivially_copyable_v<Order>);

inline std::ostream& operator<<(std::ostream& os, const Side& side) {
	if(side == Side::Buy) {
		os << "Buy";
	}else {
		os << "Sell";
	}
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const OrderType& type) {
	if(type == OrderType::Market) {
		os << "Market";
	}else {
		os << "Limit";
	}
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const Order& order) {
	os << "A " << order.side << " " << order.type
	   << " order with order ID: " << order.oid
	   << " and instrument ID: " << order.iid
	   << " placed at time: " << order.tif
	   << " and price: " << order.px
	   << " and quantity: " << order.qty << "\n";
	return os;
}

