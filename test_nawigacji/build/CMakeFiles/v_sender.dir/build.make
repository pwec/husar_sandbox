# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/justyna/ros_workspace/test_nawigacji

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/justyna/ros_workspace/test_nawigacji/build

# Include any dependencies generated for this target.
include CMakeFiles/v_sender.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/v_sender.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/v_sender.dir/flags.make

CMakeFiles/v_sender.dir/src/v_sender.o: CMakeFiles/v_sender.dir/flags.make
CMakeFiles/v_sender.dir/src/v_sender.o: ../src/v_sender.cpp
CMakeFiles/v_sender.dir/src/v_sender.o: ../manifest.xml
CMakeFiles/v_sender.dir/src/v_sender.o: /opt/ros/fuerte/share/geometry_msgs/manifest.xml
CMakeFiles/v_sender.dir/src/v_sender.o: /opt/ros/fuerte/share/roslang/manifest.xml
CMakeFiles/v_sender.dir/src/v_sender.o: /opt/ros/fuerte/share/roscpp/manifest.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /home/justyna/ros_workspace/test_nawigacji/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/v_sender.dir/src/v_sender.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/v_sender.dir/src/v_sender.o -c /home/justyna/ros_workspace/test_nawigacji/src/v_sender.cpp

CMakeFiles/v_sender.dir/src/v_sender.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/v_sender.dir/src/v_sender.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/justyna/ros_workspace/test_nawigacji/src/v_sender.cpp > CMakeFiles/v_sender.dir/src/v_sender.i

CMakeFiles/v_sender.dir/src/v_sender.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/v_sender.dir/src/v_sender.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/justyna/ros_workspace/test_nawigacji/src/v_sender.cpp -o CMakeFiles/v_sender.dir/src/v_sender.s

CMakeFiles/v_sender.dir/src/v_sender.o.requires:
.PHONY : CMakeFiles/v_sender.dir/src/v_sender.o.requires

CMakeFiles/v_sender.dir/src/v_sender.o.provides: CMakeFiles/v_sender.dir/src/v_sender.o.requires
	$(MAKE) -f CMakeFiles/v_sender.dir/build.make CMakeFiles/v_sender.dir/src/v_sender.o.provides.build
.PHONY : CMakeFiles/v_sender.dir/src/v_sender.o.provides

CMakeFiles/v_sender.dir/src/v_sender.o.provides.build: CMakeFiles/v_sender.dir/src/v_sender.o

# Object files for target v_sender
v_sender_OBJECTS = \
"CMakeFiles/v_sender.dir/src/v_sender.o"

# External object files for target v_sender
v_sender_EXTERNAL_OBJECTS =

../bin/v_sender: CMakeFiles/v_sender.dir/src/v_sender.o
../bin/v_sender: CMakeFiles/v_sender.dir/build.make
../bin/v_sender: CMakeFiles/v_sender.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/v_sender"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/v_sender.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/v_sender.dir/build: ../bin/v_sender
.PHONY : CMakeFiles/v_sender.dir/build

CMakeFiles/v_sender.dir/requires: CMakeFiles/v_sender.dir/src/v_sender.o.requires
.PHONY : CMakeFiles/v_sender.dir/requires

CMakeFiles/v_sender.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/v_sender.dir/cmake_clean.cmake
.PHONY : CMakeFiles/v_sender.dir/clean

CMakeFiles/v_sender.dir/depend:
	cd /home/justyna/ros_workspace/test_nawigacji/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justyna/ros_workspace/test_nawigacji /home/justyna/ros_workspace/test_nawigacji /home/justyna/ros_workspace/test_nawigacji/build /home/justyna/ros_workspace/test_nawigacji/build /home/justyna/ros_workspace/test_nawigacji/build/CMakeFiles/v_sender.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/v_sender.dir/depend

