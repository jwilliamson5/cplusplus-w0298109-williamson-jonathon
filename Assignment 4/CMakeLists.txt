cmake_minimum_required(VERSION 3.8)
project(Assignment_4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CppHtmlConverter.cpp CppHtmlConverter.h FilePathExample.h)
add_executable(Assignment_4 ${SOURCE_FILES})