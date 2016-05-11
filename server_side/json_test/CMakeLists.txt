cmake_minimum_required(VERSION 3.5)
project(json_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp jconverter.cpp jconverter.h jconverter_one.cpp jconverter_one.h jconverter_two.cpp jconverter_two.h)
add_executable(json_test ${SOURCE_FILES} jconverter.cpp jconverter.h jconverter_one.cpp jconverter_one.h jconverter_two.cpp jconverter_two.h)
target_link_libraries(json_test json)