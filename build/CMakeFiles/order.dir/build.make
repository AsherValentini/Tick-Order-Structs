# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/asher/HFT-Onramp/Tick-Order-Structs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/asher/HFT-Onramp/Tick-Order-Structs/build

# Include any dependencies generated for this target.
include CMakeFiles/order.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/order.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/order.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/order.dir/flags.make

CMakeFiles/order.dir/src/order_driver.cpp.o: CMakeFiles/order.dir/flags.make
CMakeFiles/order.dir/src/order_driver.cpp.o: /home/asher/HFT-Onramp/Tick-Order-Structs/src/order_driver.cpp
CMakeFiles/order.dir/src/order_driver.cpp.o: CMakeFiles/order.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asher/HFT-Onramp/Tick-Order-Structs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/order.dir/src/order_driver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/order.dir/src/order_driver.cpp.o -MF CMakeFiles/order.dir/src/order_driver.cpp.o.d -o CMakeFiles/order.dir/src/order_driver.cpp.o -c /home/asher/HFT-Onramp/Tick-Order-Structs/src/order_driver.cpp

CMakeFiles/order.dir/src/order_driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/order.dir/src/order_driver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/asher/HFT-Onramp/Tick-Order-Structs/src/order_driver.cpp > CMakeFiles/order.dir/src/order_driver.cpp.i

CMakeFiles/order.dir/src/order_driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/order.dir/src/order_driver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/asher/HFT-Onramp/Tick-Order-Structs/src/order_driver.cpp -o CMakeFiles/order.dir/src/order_driver.cpp.s

# Object files for target order
order_OBJECTS = \
"CMakeFiles/order.dir/src/order_driver.cpp.o"

# External object files for target order
order_EXTERNAL_OBJECTS =

order: CMakeFiles/order.dir/src/order_driver.cpp.o
order: CMakeFiles/order.dir/build.make
order: CMakeFiles/order.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/asher/HFT-Onramp/Tick-Order-Structs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable order"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/order.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/order.dir/build: order
.PHONY : CMakeFiles/order.dir/build

CMakeFiles/order.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/order.dir/cmake_clean.cmake
.PHONY : CMakeFiles/order.dir/clean

CMakeFiles/order.dir/depend:
	cd /home/asher/HFT-Onramp/Tick-Order-Structs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/asher/HFT-Onramp/Tick-Order-Structs /home/asher/HFT-Onramp/Tick-Order-Structs /home/asher/HFT-Onramp/Tick-Order-Structs/build /home/asher/HFT-Onramp/Tick-Order-Structs/build /home/asher/HFT-Onramp/Tick-Order-Structs/build/CMakeFiles/order.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/order.dir/depend

