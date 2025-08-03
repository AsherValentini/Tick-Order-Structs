# CMake generated Testfile for 
# Source directory: /home/asher/HFT-Onramp/Tick-Order-Structs
# Build directory: /home/asher/HFT-Onramp/Tick-Order-Structs/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(tick_order_tests "/home/asher/HFT-Onramp/Tick-Order-Structs/build/tick_order_test")
set_tests_properties(tick_order_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/asher/HFT-Onramp/Tick-Order-Structs/CMakeLists.txt;55;add_test;/home/asher/HFT-Onramp/Tick-Order-Structs/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
