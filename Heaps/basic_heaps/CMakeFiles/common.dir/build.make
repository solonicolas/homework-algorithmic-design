# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps"

# Include any dependencies generated for this target.
include CMakeFiles/common.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/common.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/common.dir/flags.make

CMakeFiles/common.dir/tests/common/array_functions.c.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/tests/common/array_functions.c.o: tests/common/array_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/common.dir/tests/common/array_functions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/common.dir/tests/common/array_functions.c.o   -c "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/array_functions.c"

CMakeFiles/common.dir/tests/common/array_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/common.dir/tests/common/array_functions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/array_functions.c" > CMakeFiles/common.dir/tests/common/array_functions.c.i

CMakeFiles/common.dir/tests/common/array_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/common.dir/tests/common/array_functions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/array_functions.c" -o CMakeFiles/common.dir/tests/common/array_functions.c.s

CMakeFiles/common.dir/tests/common/heap_functions.c.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/tests/common/heap_functions.c.o: tests/common/heap_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/common.dir/tests/common/heap_functions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/common.dir/tests/common/heap_functions.c.o   -c "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/heap_functions.c"

CMakeFiles/common.dir/tests/common/heap_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/common.dir/tests/common/heap_functions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/heap_functions.c" > CMakeFiles/common.dir/tests/common/heap_functions.c.i

CMakeFiles/common.dir/tests/common/heap_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/common.dir/tests/common/heap_functions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/heap_functions.c" -o CMakeFiles/common.dir/tests/common/heap_functions.c.s

CMakeFiles/common.dir/tests/common/test_set.c.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/tests/common/test_set.c.o: tests/common/test_set.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/common.dir/tests/common/test_set.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/common.dir/tests/common/test_set.c.o   -c "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/test_set.c"

CMakeFiles/common.dir/tests/common/test_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/common.dir/tests/common/test_set.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/test_set.c" > CMakeFiles/common.dir/tests/common/test_set.c.i

CMakeFiles/common.dir/tests/common/test_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/common.dir/tests/common/test_set.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/test_set.c" -o CMakeFiles/common.dir/tests/common/test_set.c.s

CMakeFiles/common.dir/tests/common/test_time.c.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/tests/common/test_time.c.o: tests/common/test_time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/common.dir/tests/common/test_time.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/common.dir/tests/common/test_time.c.o   -c "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/test_time.c"

CMakeFiles/common.dir/tests/common/test_time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/common.dir/tests/common/test_time.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/test_time.c" > CMakeFiles/common.dir/tests/common/test_time.c.i

CMakeFiles/common.dir/tests/common/test_time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/common.dir/tests/common/test_time.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/tests/common/test_time.c" -o CMakeFiles/common.dir/tests/common/test_time.c.s

# Object files for target common
common_OBJECTS = \
"CMakeFiles/common.dir/tests/common/array_functions.c.o" \
"CMakeFiles/common.dir/tests/common/heap_functions.c.o" \
"CMakeFiles/common.dir/tests/common/test_set.c.o" \
"CMakeFiles/common.dir/tests/common/test_time.c.o"

# External object files for target common
common_EXTERNAL_OBJECTS =

libcommon.a: CMakeFiles/common.dir/tests/common/array_functions.c.o
libcommon.a: CMakeFiles/common.dir/tests/common/heap_functions.c.o
libcommon.a: CMakeFiles/common.dir/tests/common/test_set.c.o
libcommon.a: CMakeFiles/common.dir/tests/common/test_time.c.o
libcommon.a: CMakeFiles/common.dir/build.make
libcommon.a: CMakeFiles/common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libcommon.a"
	$(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/common.dir/build: libcommon.a

.PHONY : CMakeFiles/common.dir/build

CMakeFiles/common.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean.cmake
.PHONY : CMakeFiles/common.dir/clean

CMakeFiles/common.dir/depend:
	cd "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps" "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps" "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps" "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps" "/Users/solonicolas/Desktop/Homework - Solomita Nicolas/Heaps/basic_heaps/CMakeFiles/common.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/common.dir/depend

