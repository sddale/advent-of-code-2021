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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/seth/Documents/Projects/advent_of_code_2021/day01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/seth/Documents/Projects/advent_of_code_2021/day01/build

# Include any dependencies generated for this target.
include CMakeFiles/out.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/out.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/out.dir/flags.make

CMakeFiles/out.dir/day01.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/day01.cpp.o: ../day01.cpp
CMakeFiles/out.dir/day01.cpp.o: CMakeFiles/out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seth/Documents/Projects/advent_of_code_2021/day01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/out.dir/day01.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/out.dir/day01.cpp.o -MF CMakeFiles/out.dir/day01.cpp.o.d -o CMakeFiles/out.dir/day01.cpp.o -c /Users/seth/Documents/Projects/advent_of_code_2021/day01/day01.cpp

CMakeFiles/out.dir/day01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/day01.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seth/Documents/Projects/advent_of_code_2021/day01/day01.cpp > CMakeFiles/out.dir/day01.cpp.i

CMakeFiles/out.dir/day01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/day01.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seth/Documents/Projects/advent_of_code_2021/day01/day01.cpp -o CMakeFiles/out.dir/day01.cpp.s

# Object files for target out
out_OBJECTS = \
"CMakeFiles/out.dir/day01.cpp.o"

# External object files for target out
out_EXTERNAL_OBJECTS =

out: CMakeFiles/out.dir/day01.cpp.o
out: CMakeFiles/out.dir/build.make
out: CMakeFiles/out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/seth/Documents/Projects/advent_of_code_2021/day01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/out.dir/build: out
.PHONY : CMakeFiles/out.dir/build

CMakeFiles/out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/out.dir/clean

CMakeFiles/out.dir/depend:
	cd /Users/seth/Documents/Projects/advent_of_code_2021/day01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/seth/Documents/Projects/advent_of_code_2021/day01 /Users/seth/Documents/Projects/advent_of_code_2021/day01 /Users/seth/Documents/Projects/advent_of_code_2021/day01/build /Users/seth/Documents/Projects/advent_of_code_2021/day01/build /Users/seth/Documents/Projects/advent_of_code_2021/day01/build/CMakeFiles/out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/out.dir/depend

