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
CMAKE_COMMAND = /home/federico/Documenti/clion-2019.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/federico/Documenti/clion-2019.1.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/federico/Documenti/ClionWorkspace/GameProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/core.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/core.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/core.dir/flags.make

CMakeFiles/core.dir/GameHero.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/GameHero.cpp.o: ../GameHero.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/core.dir/GameHero.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/core.dir/GameHero.cpp.o -c /home/federico/Documenti/ClionWorkspace/GameProject/GameHero.cpp

CMakeFiles/core.dir/GameHero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/GameHero.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/federico/Documenti/ClionWorkspace/GameProject/GameHero.cpp > CMakeFiles/core.dir/GameHero.cpp.i

CMakeFiles/core.dir/GameHero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/GameHero.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/federico/Documenti/ClionWorkspace/GameProject/GameHero.cpp -o CMakeFiles/core.dir/GameHero.cpp.s

CMakeFiles/core.dir/GameCharacter.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/GameCharacter.cpp.o: ../GameCharacter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/core.dir/GameCharacter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/core.dir/GameCharacter.cpp.o -c /home/federico/Documenti/ClionWorkspace/GameProject/GameCharacter.cpp

CMakeFiles/core.dir/GameCharacter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/GameCharacter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/federico/Documenti/ClionWorkspace/GameProject/GameCharacter.cpp > CMakeFiles/core.dir/GameCharacter.cpp.i

CMakeFiles/core.dir/GameCharacter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/GameCharacter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/federico/Documenti/ClionWorkspace/GameProject/GameCharacter.cpp -o CMakeFiles/core.dir/GameCharacter.cpp.s

CMakeFiles/core.dir/Map.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/Map.cpp.o: ../Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/core.dir/Map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/core.dir/Map.cpp.o -c /home/federico/Documenti/ClionWorkspace/GameProject/Map.cpp

CMakeFiles/core.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/Map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/federico/Documenti/ClionWorkspace/GameProject/Map.cpp > CMakeFiles/core.dir/Map.cpp.i

CMakeFiles/core.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/Map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/federico/Documenti/ClionWorkspace/GameProject/Map.cpp -o CMakeFiles/core.dir/Map.cpp.s

CMakeFiles/core.dir/Layer.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/Layer.cpp.o: ../Layer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/core.dir/Layer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/core.dir/Layer.cpp.o -c /home/federico/Documenti/ClionWorkspace/GameProject/Layer.cpp

CMakeFiles/core.dir/Layer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/Layer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/federico/Documenti/ClionWorkspace/GameProject/Layer.cpp > CMakeFiles/core.dir/Layer.cpp.i

CMakeFiles/core.dir/Layer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/Layer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/federico/Documenti/ClionWorkspace/GameProject/Layer.cpp -o CMakeFiles/core.dir/Layer.cpp.s

CMakeFiles/core.dir/Tile.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/Tile.cpp.o: ../Tile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/core.dir/Tile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/core.dir/Tile.cpp.o -c /home/federico/Documenti/ClionWorkspace/GameProject/Tile.cpp

CMakeFiles/core.dir/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/Tile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/federico/Documenti/ClionWorkspace/GameProject/Tile.cpp > CMakeFiles/core.dir/Tile.cpp.i

CMakeFiles/core.dir/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/Tile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/federico/Documenti/ClionWorkspace/GameProject/Tile.cpp -o CMakeFiles/core.dir/Tile.cpp.s

# Object files for target core
core_OBJECTS = \
"CMakeFiles/core.dir/GameHero.cpp.o" \
"CMakeFiles/core.dir/GameCharacter.cpp.o" \
"CMakeFiles/core.dir/Map.cpp.o" \
"CMakeFiles/core.dir/Layer.cpp.o" \
"CMakeFiles/core.dir/Tile.cpp.o"

# External object files for target core
core_EXTERNAL_OBJECTS =

libcore.a: CMakeFiles/core.dir/GameHero.cpp.o
libcore.a: CMakeFiles/core.dir/GameCharacter.cpp.o
libcore.a: CMakeFiles/core.dir/Map.cpp.o
libcore.a: CMakeFiles/core.dir/Layer.cpp.o
libcore.a: CMakeFiles/core.dir/Tile.cpp.o
libcore.a: CMakeFiles/core.dir/build.make
libcore.a: CMakeFiles/core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libcore.a"
	$(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/core.dir/build: libcore.a

.PHONY : CMakeFiles/core.dir/build

CMakeFiles/core.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean.cmake
.PHONY : CMakeFiles/core.dir/clean

CMakeFiles/core.dir/depend:
	cd /home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/federico/Documenti/ClionWorkspace/GameProject /home/federico/Documenti/ClionWorkspace/GameProject /home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug /home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug /home/federico/Documenti/ClionWorkspace/GameProject/cmake-build-debug/CMakeFiles/core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/core.dir/depend

