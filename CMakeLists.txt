cmake_minimum_required(VERSION 3.0)
project(OOLibAV VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_FIND_DEBUG_MODE TRUE)

set(OUT_INCLUDE /usr/local/include/)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(OOLibAV ${SOURCES})

set_target_properties(OOLibAV PROPERTIES VERSION ${PROJECT_VERSION})
message(${CMAKE_INSTALL_INCLUDEDIR})
# Output files
target_include_directories(OOLibAV
    PUBLIC
        ${OUT_INCLUDE}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Include libav
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
    libavdevice
    libavfilter
    libavformat
    libavcodec
    libswresample
    libswscale
    libavutil
)

# Link libav
target_link_libraries(OOLibAV PkgConfig::LIBAV)

# Installation
include(GNUInstallDirs)
install(TARGETS OOLibAV
    EXPORT OOLibAVTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Specify included headers 
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/OOLibAV
    FILES_MATCHING PATTERN "*.hpp"
)

# Export targets
export(EXPORT OOLibAVTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/OOLibAV/OOLibAVTargets.cmake"
    NAMESPACE OOLibAV::
)

# Set package version file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/OOLibAV/OOLibAVConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Generate package configuration file
configure_file("${PROJECT_SOURCE_DIR}/cmake/OOLibAVConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/OOLibAV/OOLibAVConfig.cmake"
    @ONLY
)

# Install package configuration files
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/OOLibAV/OOLibAVConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/OOLibAV/OOLibAVConfigVersion.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/OOLibAV/OOLibAVTargets.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/OOLibAV"
)

# Export package
export(PACKAGE OOLibAV)
