# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\hw1.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\hw1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\hw1.dir\flags.make

CMakeFiles\hw1.dir\AvlTests.cpp.obj: CMakeFiles\hw1.dir\flags.make
CMakeFiles\hw1.dir\AvlTests.cpp.obj: ..\AvlTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw1.dir/AvlTests.cpp.obj"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\hw1.dir\AvlTests.cpp.obj /FdCMakeFiles\hw1.dir\ /FS -c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\AvlTests.cpp"
<<

CMakeFiles\hw1.dir\AvlTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw1.dir/AvlTests.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe > CMakeFiles\hw1.dir\AvlTests.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\AvlTests.cpp"
<<

CMakeFiles\hw1.dir\AvlTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw1.dir/AvlTests.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\hw1.dir\AvlTests.cpp.s /c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\AvlTests.cpp"
<<

# Object files for target hw1
hw1_OBJECTS = \
"CMakeFiles\hw1.dir\AvlTests.cpp.obj"

# External object files for target hw1
hw1_EXTERNAL_OBJECTS =

hw1.exe: CMakeFiles\hw1.dir\AvlTests.cpp.obj
hw1.exe: CMakeFiles\hw1.dir\build.make
hw1.exe: CMakeFiles\hw1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw1.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\hw1.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\hw1.dir\objects1.rsp @<<
 /out:hw1.exe /implib:hw1.lib /pdb:"C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\hw1.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\hw1.dir\build: hw1.exe
.PHONY : CMakeFiles\hw1.dir\build

CMakeFiles\hw1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hw1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\hw1.dir\clean

CMakeFiles\hw1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1" "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1" "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug" "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug" "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\CMakeFiles\hw1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\hw1.dir\depend

