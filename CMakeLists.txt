cmake_minimum_required(VERSION 3.20)
project(Project1)
# set core flag (??)

message(STATUS "start running cmake...")

set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)

ExternalProject_Add(
        Eigen
        # Library Eigen3 is stored in the sub-folder eigen
        URL https://gitlab.com/libeigen/eigen/-/releases/3.4.0
        INSTALL_COMMAND echo "Skipping install"
)


INCLUDE_DIRECTORIES(Eigen)
INCLUDE_DIRECTORIES(tests)


ADD_EXECUTABLE(Project1
        tests/test2.cpp
        )

find_package(Boost
        COMPONENTS unit_test_framework system timer
        )
target_link_libraries(Project1 ${Boost_LIBRARIES})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS_DEBUG "-g")

set(CMAKE_CXX_FLAGS_RELEASE "-O2")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#set(CMAKE_SYSTEM_PROCESSOR arm64)
set(CMAKE_SYSTEM_PROCESSOR x86_64)


