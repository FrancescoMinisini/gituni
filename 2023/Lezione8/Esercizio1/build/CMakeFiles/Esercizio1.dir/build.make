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
CMAKE_SOURCE_DIR = /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1/build

# Include any dependencies generated for this target.
include CMakeFiles/Esercizio1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Esercizio1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Esercizio1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Esercizio1.dir/flags.make

CMakeFiles/Esercizio1.dir/main.cpp.o: CMakeFiles/Esercizio1.dir/flags.make
CMakeFiles/Esercizio1.dir/main.cpp.o: ../main.cpp
CMakeFiles/Esercizio1.dir/main.cpp.o: CMakeFiles/Esercizio1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Esercizio1.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Esercizio1.dir/main.cpp.o -MF CMakeFiles/Esercizio1.dir/main.cpp.o.d -o CMakeFiles/Esercizio1.dir/main.cpp.o -c /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1/main.cpp

CMakeFiles/Esercizio1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Esercizio1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1/main.cpp > CMakeFiles/Esercizio1.dir/main.cpp.i

CMakeFiles/Esercizio1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Esercizio1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1/main.cpp -o CMakeFiles/Esercizio1.dir/main.cpp.s

# Object files for target Esercizio1
Esercizio1_OBJECTS = \
"CMakeFiles/Esercizio1.dir/main.cpp.o"

# External object files for target Esercizio1
Esercizio1_EXTERNAL_OBJECTS =

Esercizio1: CMakeFiles/Esercizio1.dir/main.cpp.o
Esercizio1: CMakeFiles/Esercizio1.dir/build.make
Esercizio1: /snap/root-framework/936/usr/local/lib/libCore.so
Esercizio1: /snap/root-framework/936/usr/local/lib/libHist.so
Esercizio1: /snap/root-framework/936/usr/local/lib/libRIO.so
Esercizio1: /snap/root-framework/936/usr/local/lib/libGraf.so
Esercizio1: /snap/root-framework/936/usr/local/lib/libGpad.so
Esercizio1: /usr/lib/libarmadillo.so
Esercizio1: CMakeFiles/Esercizio1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Esercizio1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Esercizio1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Esercizio1.dir/build: Esercizio1
.PHONY : CMakeFiles/Esercizio1.dir/build

CMakeFiles/Esercizio1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Esercizio1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Esercizio1.dir/clean

CMakeFiles/Esercizio1.dir/depend:
	cd /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1 /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1 /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1/build /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1/build /home/francesco/programmazione/gituni/2023/Lezione8/Esercizio1/build/CMakeFiles/Esercizio1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Esercizio1.dir/depend

