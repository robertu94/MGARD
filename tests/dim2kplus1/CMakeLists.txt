cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 11)
# ENABLE ADIOS2_ROOT
if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

project(dim2kplus1 C CXX)

option(USE_TIMERS "Use profiling timers")
if(USE_TIMERS)
  message(STATUS "Enabling profiling timers")
  add_definitions(-DENABLE_TIMERS)
endif()

add_executable(dim2kplus1 dim2kplus1.cpp)

target_link_libraries(dim2kplus1 mgard)
