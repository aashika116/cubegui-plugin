cmake_minimum_required(VERSION 3.10)

# Project name
project(ParseToJSONPlugin)

# Use C++17
set(CMAKE_CXX_STANDARD 17)

# Enable Qt MOC and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

#TODO: Not sure if this is the best way to do this
#Define variables for include and library paths
set(CUBEGUI_BASE "/wsgjsc/home/suresh3/Documents/work/cubegui-install")

# CubeLib install path
set(CUBELIB_BASE "/wsgjsc/home/suresh3/Documents/work/cubelib-install")

# ================= INCLUDE DIRECTORIES =================
include_directories(
    ${CUBEGUI_BASE}/include/cubegui
    ${CUBELIB_BASE}/include/cubelib
)

# Find Qt6 (Core, Widgets, Gui)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

# ================= PLUGIN SOURCE =================
add_library(ParseToJSONPlugin SHARED
    src/ParseToJSONPlugin.cpp
    src/ParseToJSONPlugin.h
)

# Qt6 libraries
target_link_libraries(ParseToJSONPlugin PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
    ${CUBEGUI_BASE}/lib/libcube4gui.so
    ${CUBELIB_BASE}/lib/libcube4.so
)
