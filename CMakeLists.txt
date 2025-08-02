cmake_minimum_required(VERSION 3.10)
project(tick-order-structs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(core_structs INTERFACE)
target_include_directories(core_structs INTERFACE ${CMAKE_SOURCE_DIR}/include)

# Strict warnings and pedantic mode (+ padding check)
target_compile_options(core_structs
	INTERFACE
		-Wall
		-Wextra
		-Werror
		-Wconversion
		-Wpadded
		-pedantic
)

add_executable(order
	src/order_driver.cpp
)

add_executable(tick
	src/tick_driver.cpp
)

target_link_libraries(order PRIVATE core_structs)
target_link_libraries(tick PRIVATE core_structs)
