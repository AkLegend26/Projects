# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\project5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\project5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project5-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project5-test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project5-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project5-test.dir/flags.make

CMakeFiles/project5-test.dir/DblStack.cpp.obj: CMakeFiles/project5-test.dir/flags.make
CMakeFiles/project5-test.dir/DblStack.cpp.obj: ../DblStack.cpp
CMakeFiles/project5-test.dir/DblStack.cpp.obj: CMakeFiles/project5-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\project5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project5-test.dir/DblStack.cpp.obj"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project5-test.dir/DblStack.cpp.obj -MF CMakeFiles\project5-test.dir\DblStack.cpp.obj.d -o CMakeFiles\project5-test.dir\DblStack.cpp.obj -c G:\project5\DblStack.cpp

CMakeFiles/project5-test.dir/DblStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project5-test.dir/DblStack.cpp.i"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\project5\DblStack.cpp > CMakeFiles\project5-test.dir\DblStack.cpp.i

CMakeFiles/project5-test.dir/DblStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project5-test.dir/DblStack.cpp.s"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\project5\DblStack.cpp -o CMakeFiles\project5-test.dir\DblStack.cpp.s

CMakeFiles/project5-test.dir/DblStackTest.cpp.obj: CMakeFiles/project5-test.dir/flags.make
CMakeFiles/project5-test.dir/DblStackTest.cpp.obj: ../DblStackTest.cpp
CMakeFiles/project5-test.dir/DblStackTest.cpp.obj: CMakeFiles/project5-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\project5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project5-test.dir/DblStackTest.cpp.obj"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project5-test.dir/DblStackTest.cpp.obj -MF CMakeFiles\project5-test.dir\DblStackTest.cpp.obj.d -o CMakeFiles\project5-test.dir\DblStackTest.cpp.obj -c G:\project5\DblStackTest.cpp

CMakeFiles/project5-test.dir/DblStackTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project5-test.dir/DblStackTest.cpp.i"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\project5\DblStackTest.cpp > CMakeFiles\project5-test.dir\DblStackTest.cpp.i

CMakeFiles/project5-test.dir/DblStackTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project5-test.dir/DblStackTest.cpp.s"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\project5\DblStackTest.cpp -o CMakeFiles\project5-test.dir\DblStackTest.cpp.s

# Object files for target project5-test
project5__test_OBJECTS = \
"CMakeFiles/project5-test.dir/DblStack.cpp.obj" \
"CMakeFiles/project5-test.dir/DblStackTest.cpp.obj"

# External object files for target project5-test
project5__test_EXTERNAL_OBJECTS =

../project5-test.exe: CMakeFiles/project5-test.dir/DblStack.cpp.obj
../project5-test.exe: CMakeFiles/project5-test.dir/DblStackTest.cpp.obj
../project5-test.exe: CMakeFiles/project5-test.dir/build.make
../project5-test.exe: CMakeFiles/project5-test.dir/linklibs.rsp
../project5-test.exe: CMakeFiles/project5-test.dir/objects1.rsp
../project5-test.exe: CMakeFiles/project5-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\project5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ..\project5-test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\project5-test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project5-test.dir/build: ../project5-test.exe
.PHONY : CMakeFiles/project5-test.dir/build

CMakeFiles/project5-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\project5-test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/project5-test.dir/clean

CMakeFiles/project5-test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\project5 G:\project5 G:\project5\cmake-build-debug G:\project5\cmake-build-debug G:\project5\cmake-build-debug\CMakeFiles\project5-test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project5-test.dir/depend
