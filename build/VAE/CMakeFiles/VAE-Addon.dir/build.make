# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wonderstone/Desktop/VAE-addon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wonderstone/Desktop/VAE-addon/build/VAE

# Include any dependencies generated for this target.
include CMakeFiles/VAE-Addon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/VAE-Addon.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/VAE-Addon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VAE-Addon.dir/flags.make

CMakeFiles/VAE-Addon.dir/src/main.cpp.o: CMakeFiles/VAE-Addon.dir/flags.make
CMakeFiles/VAE-Addon.dir/src/main.cpp.o: /Users/wonderstone/Desktop/VAE-addon/src/main.cpp
CMakeFiles/VAE-Addon.dir/src/main.cpp.o: CMakeFiles/VAE-Addon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wonderstone/Desktop/VAE-addon/build/VAE/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VAE-Addon.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VAE-Addon.dir/src/main.cpp.o -MF CMakeFiles/VAE-Addon.dir/src/main.cpp.o.d -o CMakeFiles/VAE-Addon.dir/src/main.cpp.o -c /Users/wonderstone/Desktop/VAE-addon/src/main.cpp

CMakeFiles/VAE-Addon.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VAE-Addon.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wonderstone/Desktop/VAE-addon/src/main.cpp > CMakeFiles/VAE-Addon.dir/src/main.cpp.i

CMakeFiles/VAE-Addon.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VAE-Addon.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wonderstone/Desktop/VAE-addon/src/main.cpp -o CMakeFiles/VAE-Addon.dir/src/main.cpp.s

# Object files for target VAE-Addon
VAE__Addon_OBJECTS = \
"CMakeFiles/VAE-Addon.dir/src/main.cpp.o"

# External object files for target VAE-Addon
VAE__Addon_EXTERNAL_OBJECTS =

VAE-Addon: CMakeFiles/VAE-Addon.dir/src/main.cpp.o
VAE-Addon: CMakeFiles/VAE-Addon.dir/build.make
VAE-Addon: CMakeFiles/VAE-Addon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wonderstone/Desktop/VAE-addon/build/VAE/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable VAE-Addon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VAE-Addon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VAE-Addon.dir/build: VAE-Addon
.PHONY : CMakeFiles/VAE-Addon.dir/build

CMakeFiles/VAE-Addon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VAE-Addon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VAE-Addon.dir/clean

CMakeFiles/VAE-Addon.dir/depend:
	cd /Users/wonderstone/Desktop/VAE-addon/build/VAE && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wonderstone/Desktop/VAE-addon /Users/wonderstone/Desktop/VAE-addon /Users/wonderstone/Desktop/VAE-addon/build/VAE /Users/wonderstone/Desktop/VAE-addon/build/VAE /Users/wonderstone/Desktop/VAE-addon/build/VAE/CMakeFiles/VAE-Addon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VAE-Addon.dir/depend

