# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/janis/Documents/CellScript

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/janis/Documents/CellScript/build

# Include any dependencies generated for this target.
include CMakeFiles/CStest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CStest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CStest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CStest.dir/flags.make

CMakeFiles/CStest.dir/test.cpp.o: CMakeFiles/CStest.dir/flags.make
CMakeFiles/CStest.dir/test.cpp.o: ../test.cpp
CMakeFiles/CStest.dir/test.cpp.o: CMakeFiles/CStest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janis/Documents/CellScript/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CStest.dir/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CStest.dir/test.cpp.o -MF CMakeFiles/CStest.dir/test.cpp.o.d -o CMakeFiles/CStest.dir/test.cpp.o -c /home/janis/Documents/CellScript/test.cpp

CMakeFiles/CStest.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CStest.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/janis/Documents/CellScript/test.cpp > CMakeFiles/CStest.dir/test.cpp.i

CMakeFiles/CStest.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CStest.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/janis/Documents/CellScript/test.cpp -o CMakeFiles/CStest.dir/test.cpp.s

CMakeFiles/CStest.dir/datatypes.cc.o: CMakeFiles/CStest.dir/flags.make
CMakeFiles/CStest.dir/datatypes.cc.o: ../datatypes.cc
CMakeFiles/CStest.dir/datatypes.cc.o: CMakeFiles/CStest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janis/Documents/CellScript/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CStest.dir/datatypes.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CStest.dir/datatypes.cc.o -MF CMakeFiles/CStest.dir/datatypes.cc.o.d -o CMakeFiles/CStest.dir/datatypes.cc.o -c /home/janis/Documents/CellScript/datatypes.cc

CMakeFiles/CStest.dir/datatypes.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CStest.dir/datatypes.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/janis/Documents/CellScript/datatypes.cc > CMakeFiles/CStest.dir/datatypes.cc.i

CMakeFiles/CStest.dir/datatypes.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CStest.dir/datatypes.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/janis/Documents/CellScript/datatypes.cc -o CMakeFiles/CStest.dir/datatypes.cc.s

# Object files for target CStest
CStest_OBJECTS = \
"CMakeFiles/CStest.dir/test.cpp.o" \
"CMakeFiles/CStest.dir/datatypes.cc.o"

# External object files for target CStest
CStest_EXTERNAL_OBJECTS =

CStest: CMakeFiles/CStest.dir/test.cpp.o
CStest: CMakeFiles/CStest.dir/datatypes.cc.o
CStest: CMakeFiles/CStest.dir/build.make
CStest: CMakeFiles/CStest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/janis/Documents/CellScript/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CStest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CStest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CStest.dir/build: CStest
.PHONY : CMakeFiles/CStest.dir/build

CMakeFiles/CStest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CStest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CStest.dir/clean

CMakeFiles/CStest.dir/depend:
	cd /home/janis/Documents/CellScript/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/janis/Documents/CellScript /home/janis/Documents/CellScript /home/janis/Documents/CellScript/build /home/janis/Documents/CellScript/build /home/janis/Documents/CellScript/build/CMakeFiles/CStest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CStest.dir/depend

