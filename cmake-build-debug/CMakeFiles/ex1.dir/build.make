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
include CMakeFiles\ex1.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\ex1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\ex1.dir\flags.make

CMakeFiles\ex1.dir\Employee.cpp.obj: CMakeFiles\ex1.dir\flags.make
CMakeFiles\ex1.dir\Employee.cpp.obj: ..\Employee.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex1.dir/Employee.cpp.obj"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ex1.dir\Employee.cpp.obj /FdCMakeFiles\ex1.dir\ /FS -c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\Employee.cpp"
<<

CMakeFiles\ex1.dir\Employee.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex1.dir/Employee.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe > CMakeFiles\ex1.dir\Employee.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\Employee.cpp"
<<

CMakeFiles\ex1.dir\Employee.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex1.dir/Employee.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ex1.dir\Employee.cpp.s /c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\Employee.cpp"
<<

CMakeFiles\ex1.dir\Company.cpp.obj: CMakeFiles\ex1.dir\flags.make
CMakeFiles\ex1.dir\Company.cpp.obj: ..\Company.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ex1.dir/Company.cpp.obj"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ex1.dir\Company.cpp.obj /FdCMakeFiles\ex1.dir\ /FS -c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\Company.cpp"
<<

CMakeFiles\ex1.dir\Company.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex1.dir/Company.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe > CMakeFiles\ex1.dir\Company.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\Company.cpp"
<<

CMakeFiles\ex1.dir\Company.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex1.dir/Company.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ex1.dir\Company.cpp.s /c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\Company.cpp"
<<

CMakeFiles\ex1.dir\main1.cpp.obj: CMakeFiles\ex1.dir\flags.make
CMakeFiles\ex1.dir\main1.cpp.obj: ..\main1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ex1.dir/main1.cpp.obj"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ex1.dir\main1.cpp.obj /FdCMakeFiles\ex1.dir\ /FS -c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\main1.cpp"
<<

CMakeFiles\ex1.dir\main1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex1.dir/main1.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe > CMakeFiles\ex1.dir\main1.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\main1.cpp"
<<

CMakeFiles\ex1.dir\main1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex1.dir/main1.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ex1.dir\main1.cpp.s /c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\main1.cpp"
<<

CMakeFiles\ex1.dir\library1.cpp.obj: CMakeFiles\ex1.dir\flags.make
CMakeFiles\ex1.dir\library1.cpp.obj: ..\library1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ex1.dir/library1.cpp.obj"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ex1.dir\library1.cpp.obj /FdCMakeFiles\ex1.dir\ /FS -c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\library1.cpp"
<<

CMakeFiles\ex1.dir\library1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex1.dir/library1.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe > CMakeFiles\ex1.dir\library1.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\library1.cpp"
<<

CMakeFiles\ex1.dir\library1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex1.dir/library1.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ex1.dir\library1.cpp.s /c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\library1.cpp"
<<

CMakeFiles\ex1.dir\SalaryStat.cpp.obj: CMakeFiles\ex1.dir\flags.make
CMakeFiles\ex1.dir\SalaryStat.cpp.obj: ..\SalaryStat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ex1.dir/SalaryStat.cpp.obj"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ex1.dir\SalaryStat.cpp.obj /FdCMakeFiles\ex1.dir\ /FS -c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\SalaryStat.cpp"
<<

CMakeFiles\ex1.dir\SalaryStat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex1.dir/SalaryStat.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe > CMakeFiles\ex1.dir\SalaryStat.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\SalaryStat.cpp"
<<

CMakeFiles\ex1.dir\SalaryStat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex1.dir/SalaryStat.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ex1.dir\SalaryStat.cpp.s /c "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\SalaryStat.cpp"
<<

# Object files for target ex1
ex1_OBJECTS = \
"CMakeFiles\ex1.dir\Employee.cpp.obj" \
"CMakeFiles\ex1.dir\Company.cpp.obj" \
"CMakeFiles\ex1.dir\main1.cpp.obj" \
"CMakeFiles\ex1.dir\library1.cpp.obj" \
"CMakeFiles\ex1.dir\SalaryStat.cpp.obj"

# External object files for target ex1
ex1_EXTERNAL_OBJECTS =

ex1.exe: CMakeFiles\ex1.dir\Employee.cpp.obj
ex1.exe: CMakeFiles\ex1.dir\Company.cpp.obj
ex1.exe: CMakeFiles\ex1.dir\main1.cpp.obj
ex1.exe: CMakeFiles\ex1.dir\library1.cpp.obj
ex1.exe: CMakeFiles\ex1.dir\SalaryStat.cpp.obj
ex1.exe: CMakeFiles\ex1.dir\build.make
ex1.exe: CMakeFiles\ex1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ex1.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\ex1.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\ex1.dir\objects1.rsp @<<
 /out:ex1.exe /implib:ex1.lib /pdb:"C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\ex1.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\ex1.dir\build: ex1.exe
.PHONY : CMakeFiles\ex1.dir\build

CMakeFiles\ex1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ex1.dir\clean

CMakeFiles\ex1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1" "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1" "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug" "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug" "C:\Users\lenovo\OneDrive\Documents\programing projercts\Data Structures\ex1\cmake-build-debug\CMakeFiles\ex1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\ex1.dir\depend

