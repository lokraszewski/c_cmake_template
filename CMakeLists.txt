cmake_minimum_required(VERSION 3.11)

project(my_project
  VERSION 0.1.0
  )

include(ExternalProject)
include(CTest)

find_package(CMocka CONFIG REQUIRED)

option(FUZZ_TEST "Enable FUZZ testing" OFF)

# Check out Git submodules.
message(STATUS "Checking for submodules")
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules")
    message(STATUS "Updating submodules ")
    execute_process (COMMAND git submodule update --init --recursive
     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, defaulting to Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add libraries 
add_subdirectory(lib)

# Add application
add_subdirectory(${PROJECT_NAME})


option(WITH_EXAMPLES OFF)
option(UNIT_TESTING OFF)

add_subdirectory(test)

if(FUZZ_TEST)
	add_subdirectory(fuzz)
endif()
