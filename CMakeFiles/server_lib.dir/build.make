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
include CMakeFiles/server_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server_lib.dir/flags.make

CMakeFiles/server_lib.dir/server/server.cpp.o: CMakeFiles/server_lib.dir/flags.make
CMakeFiles/server_lib.dir/server/server.cpp.o: server/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaguar/project/hotel/Hotel_Management_System/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server_lib.dir/server/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_lib.dir/server/server.cpp.o -c /home/shaguar/project/hotel/Hotel_Management_System/server/server.cpp

CMakeFiles/server_lib.dir/server/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_lib.dir/server/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaguar/project/hotel/Hotel_Management_System/server/server.cpp > CMakeFiles/server_lib.dir/server/server.cpp.i

CMakeFiles/server_lib.dir/server/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_lib.dir/server/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaguar/project/hotel/Hotel_Management_System/server/server.cpp -o CMakeFiles/server_lib.dir/server/server.cpp.s

CMakeFiles/server_lib.dir/server/server.cpp.o.requires:

.PHONY : CMakeFiles/server_lib.dir/server/server.cpp.o.requires

CMakeFiles/server_lib.dir/server/server.cpp.o.provides: CMakeFiles/server_lib.dir/server/server.cpp.o.requires
	$(MAKE) -f CMakeFiles/server_lib.dir/build.make CMakeFiles/server_lib.dir/server/server.cpp.o.provides.build
.PHONY : CMakeFiles/server_lib.dir/server/server.cpp.o.provides

CMakeFiles/server_lib.dir/server/server.cpp.o.provides.build: CMakeFiles/server_lib.dir/server/server.cpp.o


# Object files for target server_lib
server_lib_OBJECTS = \
"CMakeFiles/server_lib.dir/server/server.cpp.o"

# External object files for target server_lib
server_lib_EXTERNAL_OBJECTS =

libserver_lib.a: CMakeFiles/server_lib.dir/server/server.cpp.o
libserver_lib.a: CMakeFiles/server_lib.dir/build.make
libserver_lib.a: CMakeFiles/server_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shaguar/project/hotel/Hotel_Management_System/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libserver_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/server_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server_lib.dir/build: libserver_lib.a

.PHONY : CMakeFiles/server_lib.dir/build

CMakeFiles/server_lib.dir/requires: CMakeFiles/server_lib.dir/server/server.cpp.o.requires

.PHONY : CMakeFiles/server_lib.dir/requires

CMakeFiles/server_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server_lib.dir/clean

CMakeFiles/server_lib.dir/depend:
	cd /home/shaguar/project/hotel/Hotel_Management_System && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shaguar/project/hotel/Hotel_Management_System /home/shaguar/project/hotel/Hotel_Management_System /home/shaguar/project/hotel/Hotel_Management_System /home/shaguar/project/hotel/Hotel_Management_System /home/shaguar/project/hotel/Hotel_Management_System/CMakeFiles/server_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server_lib.dir/depend

