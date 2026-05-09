cmake_minimum_required(VERSION 3.10)
project(PokerSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

# Exclude old Sprint 1 test/demo file from the main build.
# Backend tests are now located in tests/BackendTests.cpp.
list(FILTER SOURCES EXCLUDE REGEX ".*/testable\\.cpp$")

add_executable(PokerSim ${SOURCES})
