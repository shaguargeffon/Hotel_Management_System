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
CMAKE_BINARY_DIR = /home/shaguar/project/hotel/Hotel_Management_System/build

# Include any dependencies generated for this target.
include CMakeFiles/frame_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/frame_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/frame_lib.dir/flags.make

CMakeFiles/frame_lib.dir/frame/frame.cpp.o: CMakeFiles/frame_lib.dir/flags.make
CMakeFiles/frame_lib.dir/frame/frame.cpp.o: ../frame/frame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaguar/project/hotel/Hotel_Management_System/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/frame_lib.dir/frame/frame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame_lib.dir/frame/frame.cpp.o -c /home/shaguar/project/hotel/Hotel_Management_System/frame/frame.cpp

CMakeFiles/frame_lib.dir/frame/frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame_lib.dir/frame/frame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaguar/project/hotel/Hotel_Management_System/frame/frame.cpp > CMakeFiles/frame_lib.dir/frame/frame.cpp.i

CMakeFiles/frame_lib.dir/frame/frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame_lib.dir/frame/frame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaguar/project/hotel/Hotel_Management_System/frame/frame.cpp -o CMakeFiles/frame_lib.dir/frame/frame.cpp.s

CMakeFiles/frame_lib.dir/frame/frame.cpp.o.requires:

.PHONY : CMakeFiles/frame_lib.dir/frame/frame.cpp.o.requires

CMakeFiles/frame_lib.dir/frame/frame.cpp.o.provides: CMakeFiles/frame_lib.dir/frame/frame.cpp.o.requires
	$(MAKE) -f CMakeFiles/frame_lib.dir/build.make CMakeFiles/frame_lib.dir/frame/frame.cpp.o.provides.build
.PHONY : CMakeFiles/frame_lib.dir/frame/frame.cpp.o.provides

CMakeFiles/frame_lib.dir/frame/frame.cpp.o.provides.build: CMakeFiles/frame_lib.dir/frame/frame.cpp.o


# Object files for target frame_lib
frame_lib_OBJECTS = \
"CMakeFiles/frame_lib.dir/frame/frame.cpp.o"

# External object files for target frame_lib
frame_lib_EXTERNAL_OBJECTS =

libframe_lib.a: CMakeFiles/frame_lib.dir/frame/frame.cpp.o
libframe_lib.a: CMakeFiles/frame_lib.dir/build.make
libframe_lib.a: CMakeFiles/frame_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shaguar/project/hotel/Hotel_Management_System/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libframe_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/frame_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/frame_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/frame_lib.dir/build: libframe_lib.a

.PHONY : CMakeFiles/frame_lib.dir/build

CMakeFiles/frame_lib.dir/requires: CMakeFiles/frame_lib.dir/frame/frame.cpp.o.requires

.PHONY : CMakeFiles/frame_lib.dir/requires

CMakeFiles/frame_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/frame_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/frame_lib.dir/clean

CMakeFiles/frame_lib.dir/depend:
	cd /home/shaguar/project/hotel/Hotel_Management_System/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shaguar/project/hotel/Hotel_Management_System /home/shaguar/project/hotel/Hotel_Management_System /home/shaguar/project/hotel/Hotel_Management_System/build /home/shaguar/project/hotel/Hotel_Management_System/build /home/shaguar/project/hotel/Hotel_Management_System/build/CMakeFiles/frame_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/frame_lib.dir/depend

