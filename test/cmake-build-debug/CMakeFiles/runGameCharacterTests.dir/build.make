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
CMAKE_SOURCE_DIR = /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/runGameCharacterTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runGameCharacterTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runGameCharacterTests.dir/flags.make

CMakeFiles/runGameCharacterTests.dir/runAllTests.o: CMakeFiles/runGameCharacterTests.dir/flags.make
CMakeFiles/runGameCharacterTests.dir/runAllTests.o: ../runAllTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runGameCharacterTests.dir/runAllTests.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runGameCharacterTests.dir/runAllTests.o -c /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/runAllTests.cpp

CMakeFiles/runGameCharacterTests.dir/runAllTests.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runGameCharacterTests.dir/runAllTests.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/runAllTests.cpp > CMakeFiles/runGameCharacterTests.dir/runAllTests.i

CMakeFiles/runGameCharacterTests.dir/runAllTests.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runGameCharacterTests.dir/runAllTests.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/runAllTests.cpp -o CMakeFiles/runGameCharacterTests.dir/runAllTests.s

CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.o: CMakeFiles/runGameCharacterTests.dir/flags.make
CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.o: ../GameCharacterTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.o -c /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/GameCharacterTest.cpp

CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/GameCharacterTest.cpp > CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.i

CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/GameCharacterTest.cpp -o CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.s

CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.o: CMakeFiles/runGameCharacterTests.dir/flags.make
CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.o: ../GameCharacterFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.o -c /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/GameCharacterFixture.cpp

CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/GameCharacterFixture.cpp > CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.i

CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/GameCharacterFixture.cpp -o CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.s

# Object files for target runGameCharacterTests
runGameCharacterTests_OBJECTS = \
"CMakeFiles/runGameCharacterTests.dir/runAllTests.o" \
"CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.o" \
"CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.o"

# External object files for target runGameCharacterTests
runGameCharacterTests_EXTERNAL_OBJECTS =

runGameCharacterTests: CMakeFiles/runGameCharacterTests.dir/runAllTests.o
runGameCharacterTests: CMakeFiles/runGameCharacterTests.dir/GameCharacterTest.o
runGameCharacterTests: CMakeFiles/runGameCharacterTests.dir/GameCharacterFixture.o
runGameCharacterTests: CMakeFiles/runGameCharacterTests.dir/build.make
runGameCharacterTests: lib/libgtestd.a
runGameCharacterTests: lib/libgtest_maind.a
runGameCharacterTests: lib/libgtestd.a
runGameCharacterTests: CMakeFiles/runGameCharacterTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable runGameCharacterTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runGameCharacterTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runGameCharacterTests.dir/build: runGameCharacterTests

.PHONY : CMakeFiles/runGameCharacterTests.dir/build

CMakeFiles/runGameCharacterTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runGameCharacterTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runGameCharacterTests.dir/clean

CMakeFiles/runGameCharacterTests.dir/depend:
	cd /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/cmake-build-debug /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/cmake-build-debug /home/sode/Documenti/CLionWorkspace/unit_testing_diy/test/cmake-build-debug/CMakeFiles/runGameCharacterTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runGameCharacterTests.dir/depend

