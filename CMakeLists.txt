cmake_minimum_required(VERSION 3.10)

# Name of the project
project(SystemTreePlugin)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_library(SystemTreePlugin SHARED src/SystemTreePlugin.cpp)
target_link_libraries(SystemTreePlugin Qt6::Core Qt6::Widgets)