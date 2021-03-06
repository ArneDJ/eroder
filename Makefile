# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/foo/Projects/repos/mine/eroder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/foo/Projects/repos/mine/eroder

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/foo/Projects/repos/mine/eroder/CMakeFiles /home/foo/Projects/repos/mine/eroder//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/foo/Projects/repos/mine/eroder/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named eroder

# Build rule for target.
eroder: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 eroder
.PHONY : eroder

# fast build rule for target.
eroder/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/build
.PHONY : eroder/fast

src/camera.o: src/camera.cpp.o
.PHONY : src/camera.o

# target to build an object file
src/camera.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/camera.cpp.o
.PHONY : src/camera.cpp.o

src/camera.i: src/camera.cpp.i
.PHONY : src/camera.i

# target to preprocess a source file
src/camera.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/camera.cpp.i
.PHONY : src/camera.cpp.i

src/camera.s: src/camera.cpp.s
.PHONY : src/camera.s

# target to generate assembly for a file
src/camera.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/camera.cpp.s
.PHONY : src/camera.cpp.s

src/erode.o: src/erode.cpp.o
.PHONY : src/erode.o

# target to build an object file
src/erode.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/erode.cpp.o
.PHONY : src/erode.cpp.o

src/erode.i: src/erode.cpp.i
.PHONY : src/erode.i

# target to preprocess a source file
src/erode.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/erode.cpp.i
.PHONY : src/erode.cpp.i

src/erode.s: src/erode.cpp.s
.PHONY : src/erode.s

# target to generate assembly for a file
src/erode.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/erode.cpp.s
.PHONY : src/erode.cpp.s

src/extern/fastnoise/FastNoise.o: src/extern/fastnoise/FastNoise.cpp.o
.PHONY : src/extern/fastnoise/FastNoise.o

# target to build an object file
src/extern/fastnoise/FastNoise.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/fastnoise/FastNoise.cpp.o
.PHONY : src/extern/fastnoise/FastNoise.cpp.o

src/extern/fastnoise/FastNoise.i: src/extern/fastnoise/FastNoise.cpp.i
.PHONY : src/extern/fastnoise/FastNoise.i

# target to preprocess a source file
src/extern/fastnoise/FastNoise.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/fastnoise/FastNoise.cpp.i
.PHONY : src/extern/fastnoise/FastNoise.cpp.i

src/extern/fastnoise/FastNoise.s: src/extern/fastnoise/FastNoise.cpp.s
.PHONY : src/extern/fastnoise/FastNoise.s

# target to generate assembly for a file
src/extern/fastnoise/FastNoise.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/fastnoise/FastNoise.cpp.s
.PHONY : src/extern/fastnoise/FastNoise.cpp.s

src/extern/imgui/imgui.o: src/extern/imgui/imgui.cpp.o
.PHONY : src/extern/imgui/imgui.o

# target to build an object file
src/extern/imgui/imgui.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui.cpp.o
.PHONY : src/extern/imgui/imgui.cpp.o

src/extern/imgui/imgui.i: src/extern/imgui/imgui.cpp.i
.PHONY : src/extern/imgui/imgui.i

# target to preprocess a source file
src/extern/imgui/imgui.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui.cpp.i
.PHONY : src/extern/imgui/imgui.cpp.i

src/extern/imgui/imgui.s: src/extern/imgui/imgui.cpp.s
.PHONY : src/extern/imgui/imgui.s

# target to generate assembly for a file
src/extern/imgui/imgui.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui.cpp.s
.PHONY : src/extern/imgui/imgui.cpp.s

src/extern/imgui/imgui_demo.o: src/extern/imgui/imgui_demo.cpp.o
.PHONY : src/extern/imgui/imgui_demo.o

# target to build an object file
src/extern/imgui/imgui_demo.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_demo.cpp.o
.PHONY : src/extern/imgui/imgui_demo.cpp.o

src/extern/imgui/imgui_demo.i: src/extern/imgui/imgui_demo.cpp.i
.PHONY : src/extern/imgui/imgui_demo.i

# target to preprocess a source file
src/extern/imgui/imgui_demo.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_demo.cpp.i
.PHONY : src/extern/imgui/imgui_demo.cpp.i

src/extern/imgui/imgui_demo.s: src/extern/imgui/imgui_demo.cpp.s
.PHONY : src/extern/imgui/imgui_demo.s

# target to generate assembly for a file
src/extern/imgui/imgui_demo.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_demo.cpp.s
.PHONY : src/extern/imgui/imgui_demo.cpp.s

src/extern/imgui/imgui_draw.o: src/extern/imgui/imgui_draw.cpp.o
.PHONY : src/extern/imgui/imgui_draw.o

# target to build an object file
src/extern/imgui/imgui_draw.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_draw.cpp.o
.PHONY : src/extern/imgui/imgui_draw.cpp.o

src/extern/imgui/imgui_draw.i: src/extern/imgui/imgui_draw.cpp.i
.PHONY : src/extern/imgui/imgui_draw.i

# target to preprocess a source file
src/extern/imgui/imgui_draw.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_draw.cpp.i
.PHONY : src/extern/imgui/imgui_draw.cpp.i

src/extern/imgui/imgui_draw.s: src/extern/imgui/imgui_draw.cpp.s
.PHONY : src/extern/imgui/imgui_draw.s

# target to generate assembly for a file
src/extern/imgui/imgui_draw.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_draw.cpp.s
.PHONY : src/extern/imgui/imgui_draw.cpp.s

src/extern/imgui/imgui_impl_opengl3.o: src/extern/imgui/imgui_impl_opengl3.cpp.o
.PHONY : src/extern/imgui/imgui_impl_opengl3.o

# target to build an object file
src/extern/imgui/imgui_impl_opengl3.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_impl_opengl3.cpp.o
.PHONY : src/extern/imgui/imgui_impl_opengl3.cpp.o

src/extern/imgui/imgui_impl_opengl3.i: src/extern/imgui/imgui_impl_opengl3.cpp.i
.PHONY : src/extern/imgui/imgui_impl_opengl3.i

# target to preprocess a source file
src/extern/imgui/imgui_impl_opengl3.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_impl_opengl3.cpp.i
.PHONY : src/extern/imgui/imgui_impl_opengl3.cpp.i

src/extern/imgui/imgui_impl_opengl3.s: src/extern/imgui/imgui_impl_opengl3.cpp.s
.PHONY : src/extern/imgui/imgui_impl_opengl3.s

# target to generate assembly for a file
src/extern/imgui/imgui_impl_opengl3.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_impl_opengl3.cpp.s
.PHONY : src/extern/imgui/imgui_impl_opengl3.cpp.s

src/extern/imgui/imgui_impl_sdl.o: src/extern/imgui/imgui_impl_sdl.cpp.o
.PHONY : src/extern/imgui/imgui_impl_sdl.o

# target to build an object file
src/extern/imgui/imgui_impl_sdl.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_impl_sdl.cpp.o
.PHONY : src/extern/imgui/imgui_impl_sdl.cpp.o

src/extern/imgui/imgui_impl_sdl.i: src/extern/imgui/imgui_impl_sdl.cpp.i
.PHONY : src/extern/imgui/imgui_impl_sdl.i

# target to preprocess a source file
src/extern/imgui/imgui_impl_sdl.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_impl_sdl.cpp.i
.PHONY : src/extern/imgui/imgui_impl_sdl.cpp.i

src/extern/imgui/imgui_impl_sdl.s: src/extern/imgui/imgui_impl_sdl.cpp.s
.PHONY : src/extern/imgui/imgui_impl_sdl.s

# target to generate assembly for a file
src/extern/imgui/imgui_impl_sdl.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_impl_sdl.cpp.s
.PHONY : src/extern/imgui/imgui_impl_sdl.cpp.s

src/extern/imgui/imgui_tables.o: src/extern/imgui/imgui_tables.cpp.o
.PHONY : src/extern/imgui/imgui_tables.o

# target to build an object file
src/extern/imgui/imgui_tables.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_tables.cpp.o
.PHONY : src/extern/imgui/imgui_tables.cpp.o

src/extern/imgui/imgui_tables.i: src/extern/imgui/imgui_tables.cpp.i
.PHONY : src/extern/imgui/imgui_tables.i

# target to preprocess a source file
src/extern/imgui/imgui_tables.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_tables.cpp.i
.PHONY : src/extern/imgui/imgui_tables.cpp.i

src/extern/imgui/imgui_tables.s: src/extern/imgui/imgui_tables.cpp.s
.PHONY : src/extern/imgui/imgui_tables.s

# target to generate assembly for a file
src/extern/imgui/imgui_tables.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_tables.cpp.s
.PHONY : src/extern/imgui/imgui_tables.cpp.s

src/extern/imgui/imgui_widgets.o: src/extern/imgui/imgui_widgets.cpp.o
.PHONY : src/extern/imgui/imgui_widgets.o

# target to build an object file
src/extern/imgui/imgui_widgets.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_widgets.cpp.o
.PHONY : src/extern/imgui/imgui_widgets.cpp.o

src/extern/imgui/imgui_widgets.i: src/extern/imgui/imgui_widgets.cpp.i
.PHONY : src/extern/imgui/imgui_widgets.i

# target to preprocess a source file
src/extern/imgui/imgui_widgets.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_widgets.cpp.i
.PHONY : src/extern/imgui/imgui_widgets.cpp.i

src/extern/imgui/imgui_widgets.s: src/extern/imgui/imgui_widgets.cpp.s
.PHONY : src/extern/imgui/imgui_widgets.s

# target to generate assembly for a file
src/extern/imgui/imgui_widgets.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/extern/imgui/imgui_widgets.cpp.s
.PHONY : src/extern/imgui/imgui_widgets.cpp.s

src/image.o: src/image.cpp.o
.PHONY : src/image.o

# target to build an object file
src/image.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/image.cpp.o
.PHONY : src/image.cpp.o

src/image.i: src/image.cpp.i
.PHONY : src/image.i

# target to preprocess a source file
src/image.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/image.cpp.i
.PHONY : src/image.cpp.i

src/image.s: src/image.cpp.s
.PHONY : src/image.s

# target to generate assembly for a file
src/image.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/image.cpp.s
.PHONY : src/image.cpp.s

src/input.o: src/input.cpp.o
.PHONY : src/input.o

# target to build an object file
src/input.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/input.cpp.o
.PHONY : src/input.cpp.o

src/input.i: src/input.cpp.i
.PHONY : src/input.i

# target to preprocess a source file
src/input.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/input.cpp.i
.PHONY : src/input.cpp.i

src/input.s: src/input.cpp.s
.PHONY : src/input.s

# target to generate assembly for a file
src/input.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/input.cpp.s
.PHONY : src/input.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/mesh.o: src/mesh.cpp.o
.PHONY : src/mesh.o

# target to build an object file
src/mesh.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/mesh.cpp.o
.PHONY : src/mesh.cpp.o

src/mesh.i: src/mesh.cpp.i
.PHONY : src/mesh.i

# target to preprocess a source file
src/mesh.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/mesh.cpp.i
.PHONY : src/mesh.cpp.i

src/mesh.s: src/mesh.cpp.s
.PHONY : src/mesh.s

# target to generate assembly for a file
src/mesh.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/mesh.cpp.s
.PHONY : src/mesh.cpp.s

src/noise.o: src/noise.cpp.o
.PHONY : src/noise.o

# target to build an object file
src/noise.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/noise.cpp.o
.PHONY : src/noise.cpp.o

src/noise.i: src/noise.cpp.i
.PHONY : src/noise.i

# target to preprocess a source file
src/noise.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/noise.cpp.i
.PHONY : src/noise.cpp.i

src/noise.s: src/noise.cpp.s
.PHONY : src/noise.s

# target to generate assembly for a file
src/noise.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/noise.cpp.s
.PHONY : src/noise.cpp.s

src/shader.o: src/shader.cpp.o
.PHONY : src/shader.o

# target to build an object file
src/shader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/shader.cpp.o
.PHONY : src/shader.cpp.o

src/shader.i: src/shader.cpp.i
.PHONY : src/shader.i

# target to preprocess a source file
src/shader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/shader.cpp.i
.PHONY : src/shader.cpp.i

src/shader.s: src/shader.cpp.s
.PHONY : src/shader.s

# target to generate assembly for a file
src/shader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/shader.cpp.s
.PHONY : src/shader.cpp.s

src/texture.o: src/texture.cpp.o
.PHONY : src/texture.o

# target to build an object file
src/texture.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/texture.cpp.o
.PHONY : src/texture.cpp.o

src/texture.i: src/texture.cpp.i
.PHONY : src/texture.i

# target to preprocess a source file
src/texture.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/texture.cpp.i
.PHONY : src/texture.cpp.i

src/texture.s: src/texture.cpp.s
.PHONY : src/texture.s

# target to generate assembly for a file
src/texture.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/texture.cpp.s
.PHONY : src/texture.cpp.s

src/timer.o: src/timer.cpp.o
.PHONY : src/timer.o

# target to build an object file
src/timer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/timer.cpp.o
.PHONY : src/timer.cpp.o

src/timer.i: src/timer.cpp.i
.PHONY : src/timer.i

# target to preprocess a source file
src/timer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/timer.cpp.i
.PHONY : src/timer.cpp.i

src/timer.s: src/timer.cpp.s
.PHONY : src/timer.s

# target to generate assembly for a file
src/timer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/eroder.dir/build.make CMakeFiles/eroder.dir/src/timer.cpp.s
.PHONY : src/timer.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... eroder"
	@echo "... src/camera.o"
	@echo "... src/camera.i"
	@echo "... src/camera.s"
	@echo "... src/erode.o"
	@echo "... src/erode.i"
	@echo "... src/erode.s"
	@echo "... src/extern/fastnoise/FastNoise.o"
	@echo "... src/extern/fastnoise/FastNoise.i"
	@echo "... src/extern/fastnoise/FastNoise.s"
	@echo "... src/extern/imgui/imgui.o"
	@echo "... src/extern/imgui/imgui.i"
	@echo "... src/extern/imgui/imgui.s"
	@echo "... src/extern/imgui/imgui_demo.o"
	@echo "... src/extern/imgui/imgui_demo.i"
	@echo "... src/extern/imgui/imgui_demo.s"
	@echo "... src/extern/imgui/imgui_draw.o"
	@echo "... src/extern/imgui/imgui_draw.i"
	@echo "... src/extern/imgui/imgui_draw.s"
	@echo "... src/extern/imgui/imgui_impl_opengl3.o"
	@echo "... src/extern/imgui/imgui_impl_opengl3.i"
	@echo "... src/extern/imgui/imgui_impl_opengl3.s"
	@echo "... src/extern/imgui/imgui_impl_sdl.o"
	@echo "... src/extern/imgui/imgui_impl_sdl.i"
	@echo "... src/extern/imgui/imgui_impl_sdl.s"
	@echo "... src/extern/imgui/imgui_tables.o"
	@echo "... src/extern/imgui/imgui_tables.i"
	@echo "... src/extern/imgui/imgui_tables.s"
	@echo "... src/extern/imgui/imgui_widgets.o"
	@echo "... src/extern/imgui/imgui_widgets.i"
	@echo "... src/extern/imgui/imgui_widgets.s"
	@echo "... src/image.o"
	@echo "... src/image.i"
	@echo "... src/image.s"
	@echo "... src/input.o"
	@echo "... src/input.i"
	@echo "... src/input.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/mesh.o"
	@echo "... src/mesh.i"
	@echo "... src/mesh.s"
	@echo "... src/noise.o"
	@echo "... src/noise.i"
	@echo "... src/noise.s"
	@echo "... src/shader.o"
	@echo "... src/shader.i"
	@echo "... src/shader.s"
	@echo "... src/texture.o"
	@echo "... src/texture.i"
	@echo "... src/texture.s"
	@echo "... src/timer.o"
	@echo "... src/timer.i"
	@echo "... src/timer.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

