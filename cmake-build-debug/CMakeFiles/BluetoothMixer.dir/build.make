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
CMAKE_SOURCE_DIR = /home/sjet/CLionProjects/BMGitProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sjet/CLionProjects/BMGitProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BluetoothMixer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BluetoothMixer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BluetoothMixer.dir/flags.make

CMakeFiles/BluetoothMixer.dir/main.cpp.o: CMakeFiles/BluetoothMixer.dir/flags.make
CMakeFiles/BluetoothMixer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjet/CLionProjects/BMGitProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BluetoothMixer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BluetoothMixer.dir/main.cpp.o -c /home/sjet/CLionProjects/BMGitProject/main.cpp

CMakeFiles/BluetoothMixer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothMixer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjet/CLionProjects/BMGitProject/main.cpp > CMakeFiles/BluetoothMixer.dir/main.cpp.i

CMakeFiles/BluetoothMixer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothMixer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjet/CLionProjects/BMGitProject/main.cpp -o CMakeFiles/BluetoothMixer.dir/main.cpp.s

CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.o: CMakeFiles/BluetoothMixer.dir/flags.make
CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.o: ../UIObjs/GenericUi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjet/CLionProjects/BMGitProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.o -c /home/sjet/CLionProjects/BMGitProject/UIObjs/GenericUi.cpp

CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjet/CLionProjects/BMGitProject/UIObjs/GenericUi.cpp > CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.i

CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjet/CLionProjects/BMGitProject/UIObjs/GenericUi.cpp -o CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.s

CMakeFiles/BluetoothMixer.dir/Utils.cpp.o: CMakeFiles/BluetoothMixer.dir/flags.make
CMakeFiles/BluetoothMixer.dir/Utils.cpp.o: ../Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjet/CLionProjects/BMGitProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BluetoothMixer.dir/Utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BluetoothMixer.dir/Utils.cpp.o -c /home/sjet/CLionProjects/BMGitProject/Utils.cpp

CMakeFiles/BluetoothMixer.dir/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothMixer.dir/Utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjet/CLionProjects/BMGitProject/Utils.cpp > CMakeFiles/BluetoothMixer.dir/Utils.cpp.i

CMakeFiles/BluetoothMixer.dir/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothMixer.dir/Utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjet/CLionProjects/BMGitProject/Utils.cpp -o CMakeFiles/BluetoothMixer.dir/Utils.cpp.s

CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.o: CMakeFiles/BluetoothMixer.dir/flags.make
CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.o: ../ShellExec.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjet/CLionProjects/BMGitProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.o -c /home/sjet/CLionProjects/BMGitProject/ShellExec.cpp

CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjet/CLionProjects/BMGitProject/ShellExec.cpp > CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.i

CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjet/CLionProjects/BMGitProject/ShellExec.cpp -o CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.s

# Object files for target BluetoothMixer
BluetoothMixer_OBJECTS = \
"CMakeFiles/BluetoothMixer.dir/main.cpp.o" \
"CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.o" \
"CMakeFiles/BluetoothMixer.dir/Utils.cpp.o" \
"CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.o"

# External object files for target BluetoothMixer
BluetoothMixer_EXTERNAL_OBJECTS =

BluetoothMixer: CMakeFiles/BluetoothMixer.dir/main.cpp.o
BluetoothMixer: CMakeFiles/BluetoothMixer.dir/UIObjs/GenericUi.cpp.o
BluetoothMixer: CMakeFiles/BluetoothMixer.dir/Utils.cpp.o
BluetoothMixer: CMakeFiles/BluetoothMixer.dir/ShellExec.cpp.o
BluetoothMixer: CMakeFiles/BluetoothMixer.dir/build.make
BluetoothMixer: CMakeFiles/BluetoothMixer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sjet/CLionProjects/BMGitProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable BluetoothMixer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BluetoothMixer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BluetoothMixer.dir/build: BluetoothMixer

.PHONY : CMakeFiles/BluetoothMixer.dir/build

CMakeFiles/BluetoothMixer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BluetoothMixer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BluetoothMixer.dir/clean

CMakeFiles/BluetoothMixer.dir/depend:
	cd /home/sjet/CLionProjects/BMGitProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sjet/CLionProjects/BMGitProject /home/sjet/CLionProjects/BMGitProject /home/sjet/CLionProjects/BMGitProject/cmake-build-debug /home/sjet/CLionProjects/BMGitProject/cmake-build-debug /home/sjet/CLionProjects/BMGitProject/cmake-build-debug/CMakeFiles/BluetoothMixer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BluetoothMixer.dir/depend

