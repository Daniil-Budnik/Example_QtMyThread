cmake_minimum_required(VERSION 3.26)
project(MyThread)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(MyThread main.cpp
        Soft.cpp
        Soft.h
        MyObject.cpp
        MyObject.h)

target_link_libraries(MyThread PRIVATE Qt5::Core)
target_link_libraries(MyThread PRIVATE Qt5::Widgets)

