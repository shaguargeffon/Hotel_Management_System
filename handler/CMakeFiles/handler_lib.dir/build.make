# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
include handler/CMakeFiles/handler_lib.dir/depend.make

# Include the progress variables for this target.
include handler/CMakeFiles/handler_lib.dir/progress.make

# Include the compile flags for this target's objects.
include handler/CMakeFiles/handler_lib.dir/flags.make

handler/CMakeFiles/handler_lib.dir/handler.cpp.o: handler/CMakeFiles/handler_lib.dir/flags.make
handler/CMakeFiles/handler_lib.dir/handler.cpp.o: handler/handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaguar/project/hotel/Hotel_Management_System/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object handler/CMakeFiles/handler_lib.dir/handler.cpp.o"
	cd /home/shaguar/project/hotel/Hotel_Management_System/handler && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/handler_lib.dir/handler.cpp.o -c /home/shaguar/project/hotel/Hotel_Management_System/handler/handler.cpp

handler/CMakeFiles/handler_lib.dir/handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/handler_lib.dir/handler.cpp.i"
	cd /home/shaguar/project/hotel/Hotel_Management_System/handler && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaguar/project/hotel/Hotel_Management_System/handler/handler.cpp > CMakeFiles/handler_lib.dir/handler.cpp.i

handler/CMakeFiles/handler_lib.dir/handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/handler_lib.dir/handler.cpp.s"
	cd /home/shaguar/project/hotel/Hotel_Management_System/handler && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaguar/project/hotel/Hotel_Management_System/handler/handler.cpp -o CMakeFiles/handler_lib.dir/handler.cpp.s

handler/CMakeFiles/handler_lib.dir/handler.cpp.o.requires:

.PHONY : handler/CMakeFiles/handler_lib.dir/handler.cpp.o.requires

handler/CMakeFiles/handler_lib.dir/handler.cpp.o.provides: handler/CMakeFiles/handler_lib.dir/handler.cpp.o.requires
	$(MAKE) -f handler/CMakeFiles/handler_lib.dir/build.make handler/CMakeFiles/handler_lib.dir/handler.cpp.o.provides.build
.PHONY : handler/CMakeFiles/handler_lib.dir/handler.cpp.o.provides

handler/CMakeFiles/handler_lib.dir/handler.cpp.o.provides.build: handler/CMakeFiles/handler_lib.dir/handler.cpp.o


# Object files for target handler_lib
handler_lib_OBJECTS = \
"CMakeFiles/handler_lib.dir/handler.cpp.o"

# External object files for target handler_lib
handler_lib_EXTERNAL_OBJECTS =

handler/libhandler.a: handler/CMakeFiles/handler_lib.dir/handler.cpp.o
handler/libhandler.a: handler/CMakeFiles/handler_lib.dir/build.make
handler/libhandler.a: handler/CMakeFiles/handler_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shaguar/project/hotel/Hotel_Management_System/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhandler.a"
	cd /home/shaguar/project/hotel/Hotel_Management_System/handler && $(CMAKE_COMMAND) -P CMakeFiles/handler_lib.dir/cmake_clean_target.cmake
	cd /home/shaguar/project/hotel/Hotel_Management_System/handler && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/handler_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
handler/CMakeFiles/handler_lib.dir/build: handler/libhandler.a

.PHONY : handler/CMakeFiles/handler_lib.dir/build

handler/CMakeFiles/handler_lib.dir/requires: handler/CMakeFiles/handler_lib.dir/handler.cpp.o.requires

.PHONY : handler/CMakeFiles/handler_lib.dir/requires

handler/CMakeFiles/handler_lib.dir/clean:
	cd /home/shaguar/project/hotel/Hotel_Management_System/handler && $(CMAKE_COMMAND) -P CMakeFiles/handler_lib.dir/cmake_clean.cmake
.PHONY : handler/CMakeFiles/handler_lib.dir/clean

handler/CMakeFiles/handler_lib.dir/depend:
	cd /home/shaguar/project/hotel/Hotel_Management_System && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shaguar/project/hotel/Hotel_Management_System /home/shaguar/project/hotel/Hotel_Management_System/handler /home/shaguar/project/hotel/Hotel_Management_System /home/shaguar/project/hotel/Hotel_Management_System/handler /home/shaguar/project/hotel/Hotel_Management_System/handler/CMakeFiles/handler_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : handler/CMakeFiles/handler_lib.dir/depend

