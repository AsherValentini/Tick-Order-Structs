cmake_minimum_required(VERSION 3.10)
project(tick-order-structs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(order
	src/order_driver.cpp
)

add_executable(tick
	src/tick_driver.cpp
)

target_include_directories(order PRIVATE include src)
target_include_directories(tick PRIVATE include src)
