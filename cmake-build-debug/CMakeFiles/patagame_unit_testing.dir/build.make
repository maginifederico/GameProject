# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/sode/Scaricati/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sode/Scaricati/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sode/Documenti/CLionWorkspace/GameProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sode/Documenti/CLionWorkspace/GameProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/patagame_unit_testing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/patagame_unit_testing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/patagame_unit_testing.dir/flags.make

CMakeFiles/patagame_unit_testing.dir/main.cpp.o: CMakeFiles/patagame_unit_testing.dir/flags.make
CMakeFiles/patagame_unit_testing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sode/Documenti/CLionWorkspace/GameProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/patagame_unit_testing.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/patagame_unit_testing.dir/main.cpp.o -c /home/sode/Documenti/CLionWorkspace/GameProject/main.cpp

CMakeFiles/patagame_unit_testing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/patagame_unit_testing.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sode/Documenti/CLionWorkspace/GameProject/main.cpp > CMakeFiles/patagame_unit_testing.dir/main.cpp.i

CMakeFiles/patagame_unit_testing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/patagame_unit_testing.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sode/Documenti/CLionWorkspace/GameProject/main.cpp -o CMakeFiles/patagame_unit_testing.dir/main.cpp.s

# Object files for target patagame_unit_testing
patagame_unit_testing_OBJECTS = \
"CMakeFiles/patagame_unit_testing.dir/main.cpp.o"

# External object files for target patagame_unit_testing
patagame_unit_testing_EXTERNAL_OBJECTS =

patagame_unit_testing: CMakeFiles/patagame_unit_testing.dir/main.cpp.o
patagame_unit_testing: CMakeFiles/patagame_unit_testing.dir/build.make
patagame_unit_testing: libcore.a
patagame_unit_testing: CMakeFiles/patagame_unit_testing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sode/Documenti/CLionWorkspace/GameProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable patagame_unit_testing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/patagame_unit_testing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/patagame_unit_testing.dir/build: patagame_unit_testing

.PHONY : CMakeFiles/patagame_unit_testing.dir/build

CMakeFiles/patagame_unit_testing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/patagame_unit_testing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/patagame_unit_testing.dir/clean

CMakeFiles/patagame_unit_testing.dir/depend:
	cd /home/sode/Documenti/CLionWorkspace/GameProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sode/Documenti/CLionWorkspace/GameProject /home/sode/Documenti/CLionWorkspace/GameProject /home/sode/Documenti/CLionWorkspace/GameProject/cmake-build-debug /home/sode/Documenti/CLionWorkspace/GameProject/cmake-build-debug /home/sode/Documenti/CLionWorkspace/GameProject/cmake-build-debug/CMakeFiles/patagame_unit_testing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/patagame_unit_testing.dir/depend

