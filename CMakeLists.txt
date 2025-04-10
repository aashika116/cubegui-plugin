cmake_minimum_required(VERSION 3.10)

# Project name
project(SystemTreePlugin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

#TODO: Not sure if this is the best way to do this
#Define variables for include and library paths
set(CUBEGUI_INCLUDE_DIR /opt/cubegui/include/cubegui)

include_directories("/home/aashika/Qt/5.15.18/gcc_64/include"
"/usr/local/include/cubelib"
"/home/aashika/Downloads/Softwares/cubelib-4.8.2/src/cube/include" 
"/opt/cube/include/cubelib"
"/home/aashika/Downloads/Softwares/cubegui-4.8.2/src/GUI-qt/display"
"/home/aashika/Qt/5.15.18/Src/qt3d/src/3rdparty/assimp/src/include/assimp"
)

set(CUBEGUI_LIB_DIR /opt/cubegui/lib)
set(CUBELIB_LIB_DIR /usr/local/include/cubelib)
set(QT_LIB_DIR /home/aashika/Qt/5.15.18/gcc_64/lib)

include_directories(${CUBEGUI_INCLUDE_DIR} ${CUBELIB_INCLUDE_DIR})

set(CMAKE_PREFIX_PATH "/home/aashika/Qt/5.15.18/gcc_64/lib/cmake/Qt5")

find_package(Qt5 5.15.18 REQUIRED COMPONENTS Core Widgets)

add_library(SystemTreePlugin SHARED
    src/SystemTreePlugin.cpp
    src/SystemTreePlugin.h
)
target_link_libraries(SystemTreePlugin PRIVATE
    Qt5::Core
    Qt5::Widgets
)