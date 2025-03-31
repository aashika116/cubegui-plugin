cmake_minimum_required(VERSION 3.10)

# Project name
project(SystemTreePlugin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# TODO: Not sure if this is the best way to do this.
# Define variables for include and library paths
set(CUBEGUI_INCLUDE_DIR /opt/cubegui/include/cubegui)
set(CUBELIB_INCLUDE_DIR /usr/local/include/cubelib)
set(QT_INCLUDE_DIR /home/aashika/Qt6.8.0/6.8.0/gcc_64/include)

set(CUBEGUI_LIB_DIR /opt/cubegui/lib)
set(CUBELIB_LIB_DIR /usr/local/include/cubelib)
set(QT_LIB_DIR /home/aashika/Qt6.8.0/6.8.0/gcc_64/lib)

include_directories(${CUBEGUI_INCLUDE_DIR} ${CUBELIB_INCLUDE_DIR} ${QT_INCLUDE_DIR})
link_directories(${CUBEGUI_LIB_DIR} ${CUBELIB_LIB_DIR} ${QT_LIB_DIR})

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_library(SystemTreePlugin SHARED
    src/SystemTreePlugin.cpp
    src/SystemTreePlugin.h
)
target_link_libraries(SystemTreePlugin
    Qt6::Core
    Qt6::Widgets
)