# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/team/SoftwareDevelopment/ROS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/team/SoftwareDevelopment/ROS/build

# Include any dependencies generated for this target.
include logic/CMakeFiles/logic_node.dir/depend.make

# Include the progress variables for this target.
include logic/CMakeFiles/logic_node.dir/progress.make

# Include the compile flags for this target's objects.
include logic/CMakeFiles/logic_node.dir/flags.make

logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o: logic/CMakeFiles/logic_node.dir/flags.make
logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o: /home/team/SoftwareDevelopment/ROS/src/logic/src/logic_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/team/SoftwareDevelopment/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o"
	cd /home/team/SoftwareDevelopment/ROS/build/logic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logic_node.dir/src/logic_node.cpp.o -c /home/team/SoftwareDevelopment/ROS/src/logic/src/logic_node.cpp

logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logic_node.dir/src/logic_node.cpp.i"
	cd /home/team/SoftwareDevelopment/ROS/build/logic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/team/SoftwareDevelopment/ROS/src/logic/src/logic_node.cpp > CMakeFiles/logic_node.dir/src/logic_node.cpp.i

logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logic_node.dir/src/logic_node.cpp.s"
	cd /home/team/SoftwareDevelopment/ROS/build/logic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/team/SoftwareDevelopment/ROS/src/logic/src/logic_node.cpp -o CMakeFiles/logic_node.dir/src/logic_node.cpp.s

logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o.requires:

.PHONY : logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o.requires

logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o.provides: logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o.requires
	$(MAKE) -f logic/CMakeFiles/logic_node.dir/build.make logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o.provides.build
.PHONY : logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o.provides

logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o.provides.build: logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o


# Object files for target logic_node
logic_node_OBJECTS = \
"CMakeFiles/logic_node.dir/src/logic_node.cpp.o"

# External object files for target logic_node
logic_node_EXTERNAL_OBJECTS =

/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: logic/CMakeFiles/logic_node.dir/build.make
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /opt/ros/melodic/lib/libroscpp.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /usr/lib/aarch64-linux-gnu/libboost_filesystem.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /opt/ros/melodic/lib/librosconsole.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /usr/lib/aarch64-linux-gnu/liblog4cxx.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /usr/lib/aarch64-linux-gnu/libboost_regex.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /opt/ros/melodic/lib/librostime.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /opt/ros/melodic/lib/libcpp_common.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /usr/lib/aarch64-linux-gnu/libboost_system.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /usr/lib/aarch64-linux-gnu/libboost_thread.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /usr/lib/aarch64-linux-gnu/libboost_chrono.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /usr/lib/aarch64-linux-gnu/libboost_date_time.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /usr/lib/aarch64-linux-gnu/libboost_atomic.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /usr/lib/aarch64-linux-gnu/libpthread.so
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: /usr/lib/aarch64-linux-gnu/libconsole_bridge.so.0.4
/home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node: logic/CMakeFiles/logic_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/team/SoftwareDevelopment/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node"
	cd /home/team/SoftwareDevelopment/ROS/build/logic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logic_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
logic/CMakeFiles/logic_node.dir/build: /home/team/SoftwareDevelopment/ROS/devel/lib/logic/logic_node

.PHONY : logic/CMakeFiles/logic_node.dir/build

logic/CMakeFiles/logic_node.dir/requires: logic/CMakeFiles/logic_node.dir/src/logic_node.cpp.o.requires

.PHONY : logic/CMakeFiles/logic_node.dir/requires

logic/CMakeFiles/logic_node.dir/clean:
	cd /home/team/SoftwareDevelopment/ROS/build/logic && $(CMAKE_COMMAND) -P CMakeFiles/logic_node.dir/cmake_clean.cmake
.PHONY : logic/CMakeFiles/logic_node.dir/clean

logic/CMakeFiles/logic_node.dir/depend:
	cd /home/team/SoftwareDevelopment/ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/team/SoftwareDevelopment/ROS/src /home/team/SoftwareDevelopment/ROS/src/logic /home/team/SoftwareDevelopment/ROS/build /home/team/SoftwareDevelopment/ROS/build/logic /home/team/SoftwareDevelopment/ROS/build/logic/CMakeFiles/logic_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : logic/CMakeFiles/logic_node.dir/depend
