cmake_minimum_required(VERSION 3.5)
project(sync_server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(sync_server ${SOURCE_FILES})

target_link_libraries(sync_server json)