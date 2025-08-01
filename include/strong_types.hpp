#pragma once
#include <type_traits>

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

private:
	T value_;
};