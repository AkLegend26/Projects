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
CMAKE_SOURCE_DIR = G:\project0-Windows

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\project0-Windows\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project0.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project0.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project0.dir/flags.make

CMakeFiles/project0.dir/CalTest.cpp.obj: CMakeFiles/project0.dir/flags.make
CMakeFiles/project0.dir/CalTest.cpp.obj: ../CalTest.cpp
CMakeFiles/project0.dir/CalTest.cpp.obj: CMakeFiles/project0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\project0-Windows\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project0.dir/CalTest.cpp.obj"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project0.dir/CalTest.cpp.obj -MF CMakeFiles\project0.dir\CalTest.cpp.obj.d -o CMakeFiles\project0.dir\CalTest.cpp.obj -c G:\project0-Windows\CalTest.cpp

CMakeFiles/project0.dir/CalTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project0.dir/CalTest.cpp.i"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\project0-Windows\CalTest.cpp > CMakeFiles\project0.dir\CalTest.cpp.i

CMakeFiles/project0.dir/CalTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project0.dir/CalTest.cpp.s"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\project0-Windows\CalTest.cpp -o CMakeFiles\project0.dir\CalTest.cpp.s

CMakeFiles/project0.dir/Date.cpp.obj: CMakeFiles/project0.dir/flags.make
CMakeFiles/project0.dir/Date.cpp.obj: ../Date.cpp
CMakeFiles/project0.dir/Date.cpp.obj: CMakeFiles/project0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\project0-Windows\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project0.dir/Date.cpp.obj"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project0.dir/Date.cpp.obj -MF CMakeFiles\project0.dir\Date.cpp.obj.d -o CMakeFiles\project0.dir\Date.cpp.obj -c G:\project0-Windows\Date.cpp

CMakeFiles/project0.dir/Date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project0.dir/Date.cpp.i"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\project0-Windows\Date.cpp > CMakeFiles\project0.dir\Date.cpp.i

CMakeFiles/project0.dir/Date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project0.dir/Date.cpp.s"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\project0-Windows\Date.cpp -o CMakeFiles\project0.dir\Date.cpp.s

CMakeFiles/project0.dir/Reminder.cpp.obj: CMakeFiles/project0.dir/flags.make
CMakeFiles/project0.dir/Reminder.cpp.obj: ../Reminder.cpp
CMakeFiles/project0.dir/Reminder.cpp.obj: CMakeFiles/project0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\project0-Windows\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project0.dir/Reminder.cpp.obj"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project0.dir/Reminder.cpp.obj -MF CMakeFiles\project0.dir\Reminder.cpp.obj.d -o CMakeFiles\project0.dir\Reminder.cpp.obj -c G:\project0-Windows\Reminder.cpp

CMakeFiles/project0.dir/Reminder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project0.dir/Reminder.cpp.i"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\project0-Windows\Reminder.cpp > CMakeFiles\project0.dir\Reminder.cpp.i

CMakeFiles/project0.dir/Reminder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project0.dir/Reminder.cpp.s"
	C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\project0-Windows\Reminder.cpp -o CMakeFiles\project0.dir\Reminder.cpp.s

# Object files for target project0
project0_OBJECTS = \
"CMakeFiles/project0.dir/CalTest.cpp.obj" \
"CMakeFiles/project0.dir/Date.cpp.obj" \
"CMakeFiles/project0.dir/Reminder.cpp.obj"

# External object files for target project0
project0_EXTERNAL_OBJECTS = \
"G:/project0-Windows/Calendar.cpp.obj"

project0.exe: CMakeFiles/project0.dir/CalTest.cpp.obj
project0.exe: CMakeFiles/project0.dir/Date.cpp.obj
project0.exe: CMakeFiles/project0.dir/Reminder.cpp.obj
project0.exe: ../Calendar.cpp.obj
project0.exe: CMakeFiles/project0.dir/build.make
project0.exe: CMakeFiles/project0.dir/linklibs.rsp
project0.exe: CMakeFiles/project0.dir/objects1.rsp
project0.exe: CMakeFiles/project0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\project0-Windows\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable project0.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\project0.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project0.dir/build: project0.exe
.PHONY : CMakeFiles/project0.dir/build

CMakeFiles/project0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\project0.dir\cmake_clean.cmake
.PHONY : CMakeFiles/project0.dir/clean

CMakeFiles/project0.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\project0-Windows G:\project0-Windows G:\project0-Windows\cmake-build-debug G:\project0-Windows\cmake-build-debug G:\project0-Windows\cmake-build-debug\CMakeFiles\project0.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project0.dir/depend

