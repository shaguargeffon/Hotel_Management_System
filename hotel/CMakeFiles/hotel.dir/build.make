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
CMAKE_SOURCE_DIR = /home/shaguar/project/hotel/Hotel_Management_System

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shaguar/project/hotel/Hotel_Management_System

# Include any dependencies generated for this target.
include hotel/CMakeFiles/hotel.dir/depend.make

# Include the progress variables for this target.
include hotel/CMakeFiles/hotel.dir/progress.make

# Include the compile flags for this target's objects.
include hotel/CMakeFiles/hotel.dir/flags.make

hotel/CMakeFiles/hotel.dir/hotel.cpp.o: hotel/CMakeFiles/hotel.dir/flags.make
hotel/CMakeFiles/hotel.dir/hotel.cpp.o: hotel/hotel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaguar/project/hotel/Hotel_Management_System/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object hotel/CMakeFiles/hotel.dir/hotel.cpp.o"
	cd /home/shaguar/project/hotel/Hotel_Management_System/hotel && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hotel.dir/hotel.cpp.o -c /home/shaguar/project/hotel/Hotel_Management_System/hotel/hotel.cpp

hotel/CMakeFiles/hotel.dir/hotel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hotel.dir/hotel.cpp.i"
	cd /home/shaguar/project/hotel/Hotel_Management_System/hotel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaguar/project/hotel/Hotel_Management_System/hotel/hotel.cpp > CMakeFiles/hotel.dir/hotel.cpp.i

hotel/CMakeFiles/hotel.dir/hotel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hotel.dir/hotel.cpp.s"
	cd /home/shaguar/project/hotel/Hotel_Management_System/hotel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaguar/project/hotel/Hotel_Management_System/hotel/hotel.cpp -o CMakeFiles/hotel.dir/hotel.cpp.s

hotel/CMakeFiles/hotel.dir/hotel.cpp.o.requires:

.PHONY : hotel/CMakeFiles/hotel.dir/hotel.cpp.o.requires

hotel/CMakeFiles/hotel.dir/hotel.cpp.o.provides: hotel/CMakeFiles/hotel.dir/hotel.cpp.o.requires
	$(MAKE) -f hotel/CMakeFiles/hotel.dir/build.make hotel/CMakeFiles/hotel.dir/hotel.cpp.o.provides.build
.PHONY : hotel/CMakeFiles/hotel.dir/hotel.cpp.o.provides

hotel/CMakeFiles/hotel.dir/hotel.cpp.o.provides.build: hotel/CMakeFiles/hotel.dir/hotel.cpp.o


# Object files for target hotel
hotel_OBJECTS = \
"CMakeFiles/hotel.dir/hotel.cpp.o"

# External object files for target hotel
hotel_EXTERNAL_OBJECTS =

hotel/libhotel.a: hotel/CMakeFiles/hotel.dir/hotel.cpp.o
hotel/libhotel.a: hotel/CMakeFiles/hotel.dir/build.make
hotel/libhotel.a: hotel/CMakeFiles/hotel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shaguar/project/hotel/Hotel_Management_System/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhotel.a"
	cd /home/shaguar/project/hotel/Hotel_Management_System/hotel && $(CMAKE_COMMAND) -P CMakeFiles/hotel.dir/cmake_clean_target.cmake
	cd /home/shaguar/project/hotel/Hotel_Management_System/hotel && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hotel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hotel/CMakeFiles/hotel.dir/build: hotel/libhotel.a

.PHONY : hotel/CMakeFiles/hotel.dir/build

hotel/CMakeFiles/hotel.dir/requires: hotel/CMakeFiles/hotel.dir/hotel.cpp.o.requires

.PHONY : hotel/CMakeFiles/hotel.dir/requires

hotel/CMakeFiles/hotel.dir/clean:
	cd /home/shaguar/project/hotel/Hotel_Management_System/hotel && $(CMAKE_COMMAND) -P CMakeFiles/hotel.dir/cmake_clean.cmake
.PHONY : hotel/CMakeFiles/hotel.dir/clean

hotel/CMakeFiles/hotel.dir/depend:
	cd /home/shaguar/project/hotel/Hotel_Management_System && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shaguar/project/hotel/Hotel_Management_System /home/shaguar/project/hotel/Hotel_Management_System/hotel /home/shaguar/project/hotel/Hotel_Management_System /home/shaguar/project/hotel/Hotel_Management_System/hotel /home/shaguar/project/hotel/Hotel_Management_System/hotel/CMakeFiles/hotel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : hotel/CMakeFiles/hotel.dir/depend

