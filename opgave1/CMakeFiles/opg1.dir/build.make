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

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/drew/opgave1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/drew/opgave1

# Include any dependencies generated for this target.
include CMakeFiles/opg1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opg1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opg1.dir/flags.make

CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o: CMakeFiles/opg1.dir/flags.make
CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o: Andreas_DeLille_opgave1.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/drew/opgave1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o -c /home/drew/opgave1/Andreas_DeLille_opgave1.cpp

CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/drew/opgave1/Andreas_DeLille_opgave1.cpp > CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.i

CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/drew/opgave1/Andreas_DeLille_opgave1.cpp -o CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.s

CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o.requires:
.PHONY : CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o.requires

CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o.provides: CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o.requires
	$(MAKE) -f CMakeFiles/opg1.dir/build.make CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o.provides.build
.PHONY : CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o.provides

CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o.provides.build: CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o

# Object files for target opg1
opg1_OBJECTS = \
"CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o"

# External object files for target opg1
opg1_EXTERNAL_OBJECTS =

bin/opg1: CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o
bin/opg1: CMakeFiles/opg1.dir/build.make
bin/opg1: CMakeFiles/opg1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/opg1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opg1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opg1.dir/build: bin/opg1
.PHONY : CMakeFiles/opg1.dir/build

CMakeFiles/opg1.dir/requires: CMakeFiles/opg1.dir/Andreas_DeLille_opgave1.o.requires
.PHONY : CMakeFiles/opg1.dir/requires

CMakeFiles/opg1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opg1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opg1.dir/clean

CMakeFiles/opg1.dir/depend:
	cd /home/drew/opgave1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/drew/opgave1 /home/drew/opgave1 /home/drew/opgave1 /home/drew/opgave1 /home/drew/opgave1/CMakeFiles/opg1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opg1.dir/depend

