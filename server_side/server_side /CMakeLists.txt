cmake_minimum_required(VERSION 3.5)
project(server_side)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp jconverter.cpp jconverter.h  db_client.cpp db_client.h server.cpp server.h ss_exception.cpp ss_exception.h)
add_executable(server_side ${SOURCE_FILES} jconverter.cpp jconverter.h  db_client.cpp db_client.h server.cpp server.h ss_exception.cpp ss_exception.h)

target_link_libraries(server_side json mysqlclient)