cmake_minimum_required(VERSION 3.0)

project (queues_example
        VERSION 0.1
        LANGUAGES CXX C)

#############################
# Setup Target Names
#############################
set(PROGRAM_EXE_NAME ${PROJECT_NAME})


#############################
# Setup Compiler flags / Compile time Vars
#############################
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-g -O0 --coverage")

#############################
# Setup Common Include directories
#############################
set(COMPONENT_TOP ${CMAKE_CURRENT_SOURCE_DIR})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


#############################
# Build Sub-Targets
#############################
add_subdirectory(src)

message(STATUS "${CMAKE_CURRENT_SOURCE_DIR} -- ${PROJECT_NAME}")
