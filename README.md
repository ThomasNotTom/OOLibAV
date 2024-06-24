# OOLibAV (Object-Oriented LibAV)

## Pre-requisites

To build the project you must have a version of LibAV installed (included with [FFMpeg](https://ffmpeg.org)), and accessible with pkg-config. If your installation of LibAV differs, you may edit the CMakeLists.txt to include LibAV how you would like.

By default, the header files are compiled to '/usr/local/include/OOLibAV' however this can be changed by altering the 'OUT_INCLUDE' variable in the CMake file.

You will also need [Git](https://git-scm.com), [CMake](https://cmake.org) and [Make](https://www.gnu.org/software/make/manual/make.html) installed.

## Building

0. Clone the repository

```bash
git clone https://github.com/ThomasNotTom/OOLibAV.git
```

1. Go into the project, then build folder
```bash
cd OOLibAV
cd build
```

2. Run cmake
```bash
cmake ..
```

3. Run make
```bash
make
```

4. Install with make
```bash
sudo make install
```

## Including OOLibAV
To include the project in your CMake file you will need to find the package and link the library. You will also need to include LibAV.

For example

```CMake
cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

# Find OOLibAV and PkgConfig package using find_package
find_package(OOLibAV REQUIRED)
find_package(PkgConfig REQUIRED)

# Add your executable
add_executable(main 
    ./src/main.cpp
)

# Include all LibAV components
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
    libavdevice
    libavfilter
    libavformat
    libavcodec
    libswresample
    libswscale
    libavutil
)

# Link OOLibAV and LibAV libraries
target_link_libraries(main PRIVATE OOLibAV::OOLibAV PkgConfig::LIBAV)

```