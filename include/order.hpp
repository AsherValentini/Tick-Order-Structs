#pragma once
#include <iostream>
#include "strong_types.hpp"

enum class Side {
	Buy,
	Sell
};

enum class OrderType {
	Limit,
	Market
};

struct Order {
	OrderId oid;
	InstrumentId iid;
	Side side;
	Price px;
	Qty qty;
	TimeInForce tif;
	OrderType type;

	Order(OrderId o, InstrumentId i, Side s, Price p, Qty q, TimeInForce t, OrderType ot)
    		: oid(o), iid(i), side(s), px(p), qty(q), tif(t), type(ot) {}

};

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

