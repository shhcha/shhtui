cmake_minimum_required(VERSION 3.16)
project(shhtui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library
add_library(shhtui
    src/util.cpp
    src/renderer.cpp
)

target_include_directories(shhtui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Example executable
add_executable(example     ${CMAKE_CURRENT_SOURCE_DIR}/example/example.cpp)
target_link_libraries(example PRIVATE shhtui)
