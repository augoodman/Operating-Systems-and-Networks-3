# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/123/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/123/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrew/CLionProjects/Module3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/CLionProjects/Module3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Module3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Module3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Module3.dir/flags.make

CMakeFiles/Module3.dir/BmpProcessor.c.o: CMakeFiles/Module3.dir/flags.make
CMakeFiles/Module3.dir/BmpProcessor.c.o: ../BmpProcessor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/CLionProjects/Module3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Module3.dir/BmpProcessor.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Module3.dir/BmpProcessor.c.o   -c /home/andrew/CLionProjects/Module3/BmpProcessor.c

CMakeFiles/Module3.dir/BmpProcessor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Module3.dir/BmpProcessor.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrew/CLionProjects/Module3/BmpProcessor.c > CMakeFiles/Module3.dir/BmpProcessor.c.i

CMakeFiles/Module3.dir/BmpProcessor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Module3.dir/BmpProcessor.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrew/CLionProjects/Module3/BmpProcessor.c -o CMakeFiles/Module3.dir/BmpProcessor.c.s

CMakeFiles/Module3.dir/GoodmanImageProcessor.c.o: CMakeFiles/Module3.dir/flags.make
CMakeFiles/Module3.dir/GoodmanImageProcessor.c.o: ../GoodmanImageProcessor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/CLionProjects/Module3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Module3.dir/GoodmanImageProcessor.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Module3.dir/GoodmanImageProcessor.c.o   -c /home/andrew/CLionProjects/Module3/GoodmanImageProcessor.c

CMakeFiles/Module3.dir/GoodmanImageProcessor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Module3.dir/GoodmanImageProcessor.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrew/CLionProjects/Module3/GoodmanImageProcessor.c > CMakeFiles/Module3.dir/GoodmanImageProcessor.c.i

CMakeFiles/Module3.dir/GoodmanImageProcessor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Module3.dir/GoodmanImageProcessor.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrew/CLionProjects/Module3/GoodmanImageProcessor.c -o CMakeFiles/Module3.dir/GoodmanImageProcessor.c.s

CMakeFiles/Module3.dir/PixelProcessor.c.o: CMakeFiles/Module3.dir/flags.make
CMakeFiles/Module3.dir/PixelProcessor.c.o: ../PixelProcessor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/CLionProjects/Module3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Module3.dir/PixelProcessor.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Module3.dir/PixelProcessor.c.o   -c /home/andrew/CLionProjects/Module3/PixelProcessor.c

CMakeFiles/Module3.dir/PixelProcessor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Module3.dir/PixelProcessor.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrew/CLionProjects/Module3/PixelProcessor.c > CMakeFiles/Module3.dir/PixelProcessor.c.i

CMakeFiles/Module3.dir/PixelProcessor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Module3.dir/PixelProcessor.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrew/CLionProjects/Module3/PixelProcessor.c -o CMakeFiles/Module3.dir/PixelProcessor.c.s

CMakeFiles/Module3.dir/PpmProcessor.c.o: CMakeFiles/Module3.dir/flags.make
CMakeFiles/Module3.dir/PpmProcessor.c.o: ../PpmProcessor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/CLionProjects/Module3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Module3.dir/PpmProcessor.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Module3.dir/PpmProcessor.c.o   -c /home/andrew/CLionProjects/Module3/PpmProcessor.c

CMakeFiles/Module3.dir/PpmProcessor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Module3.dir/PpmProcessor.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrew/CLionProjects/Module3/PpmProcessor.c > CMakeFiles/Module3.dir/PpmProcessor.c.i

CMakeFiles/Module3.dir/PpmProcessor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Module3.dir/PpmProcessor.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrew/CLionProjects/Module3/PpmProcessor.c -o CMakeFiles/Module3.dir/PpmProcessor.c.s

CMakeFiles/Module3.dir/Util.c.o: CMakeFiles/Module3.dir/flags.make
CMakeFiles/Module3.dir/Util.c.o: ../Util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/CLionProjects/Module3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Module3.dir/Util.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Module3.dir/Util.c.o   -c /home/andrew/CLionProjects/Module3/Util.c

CMakeFiles/Module3.dir/Util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Module3.dir/Util.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrew/CLionProjects/Module3/Util.c > CMakeFiles/Module3.dir/Util.c.i

CMakeFiles/Module3.dir/Util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Module3.dir/Util.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrew/CLionProjects/Module3/Util.c -o CMakeFiles/Module3.dir/Util.c.s

# Object files for target Module3
Module3_OBJECTS = \
"CMakeFiles/Module3.dir/BmpProcessor.c.o" \
"CMakeFiles/Module3.dir/GoodmanImageProcessor.c.o" \
"CMakeFiles/Module3.dir/PixelProcessor.c.o" \
"CMakeFiles/Module3.dir/PpmProcessor.c.o" \
"CMakeFiles/Module3.dir/Util.c.o"

# External object files for target Module3
Module3_EXTERNAL_OBJECTS =

Module3: CMakeFiles/Module3.dir/BmpProcessor.c.o
Module3: CMakeFiles/Module3.dir/GoodmanImageProcessor.c.o
Module3: CMakeFiles/Module3.dir/PixelProcessor.c.o
Module3: CMakeFiles/Module3.dir/PpmProcessor.c.o
Module3: CMakeFiles/Module3.dir/Util.c.o
Module3: CMakeFiles/Module3.dir/build.make
Module3: CMakeFiles/Module3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrew/CLionProjects/Module3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Module3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Module3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Module3.dir/build: Module3

.PHONY : CMakeFiles/Module3.dir/build

CMakeFiles/Module3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Module3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Module3.dir/clean

CMakeFiles/Module3.dir/depend:
	cd /home/andrew/CLionProjects/Module3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/CLionProjects/Module3 /home/andrew/CLionProjects/Module3 /home/andrew/CLionProjects/Module3/cmake-build-debug /home/andrew/CLionProjects/Module3/cmake-build-debug /home/andrew/CLionProjects/Module3/cmake-build-debug/CMakeFiles/Module3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Module3.dir/depend

