cmake_minimum_required (VERSION 3.5)
set ( CMAKE_CXX_COMPILER "/usr/bin/g++" )
set ( CMAKE_C_COMPILER "/usr/bin/gcc" )
project(render-me)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB SOURCES *.h *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
 