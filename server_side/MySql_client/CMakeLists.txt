cmake_minimum_required(VERSION 3.5)
project(MySql_client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("/usr/include/mysql")

set(SOURCE_FILES main.cpp db_client.cpp db_client.h app_request.cpp app_request.h)

add_executable(MySql_client ${SOURCE_FILES})

target_link_libraries (MySql_client mysqlclient)
