# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/di/project/Hotel_Management_System

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/di/project/Hotel_Management_System/build

# Include any dependencies generated for this target.
include CMakeFiles/myhotel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myhotel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myhotel.dir/flags.make

CMakeFiles/myhotel.dir/main.cpp.o: CMakeFiles/myhotel.dir/flags.make
CMakeFiles/myhotel.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/di/project/Hotel_Management_System/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myhotel.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myhotel.dir/main.cpp.o -c /home/di/project/Hotel_Management_System/main.cpp

CMakeFiles/myhotel.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myhotel.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/di/project/Hotel_Management_System/main.cpp > CMakeFiles/myhotel.dir/main.cpp.i

CMakeFiles/myhotel.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myhotel.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/di/project/Hotel_Management_System/main.cpp -o CMakeFiles/myhotel.dir/main.cpp.s

# Object files for target myhotel
myhotel_OBJECTS = \
"CMakeFiles/myhotel.dir/main.cpp.o"

# External object files for target myhotel
myhotel_EXTERNAL_OBJECTS =

myhotel: CMakeFiles/myhotel.dir/main.cpp.o
myhotel: CMakeFiles/myhotel.dir/build.make
myhotel: database/libdatabase.a
myhotel: server/libserver_lib.a
myhotel: handler/libhandler.a
myhotel: CMakeFiles/myhotel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/di/project/Hotel_Management_System/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable myhotel"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myhotel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myhotel.dir/build: myhotel

.PHONY : CMakeFiles/myhotel.dir/build

CMakeFiles/myhotel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myhotel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myhotel.dir/clean

CMakeFiles/myhotel.dir/depend:
	cd /home/di/project/Hotel_Management_System/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/di/project/Hotel_Management_System /home/di/project/Hotel_Management_System /home/di/project/Hotel_Management_System/build /home/di/project/Hotel_Management_System/build /home/di/project/Hotel_Management_System/build/CMakeFiles/myhotel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myhotel.dir/depend

