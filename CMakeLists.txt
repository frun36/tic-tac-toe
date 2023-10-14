cmake_minimum_required(VERSION 3.22)

project(Tic-Tac-Toe LANGUAGES CXX)

include_directories(include)

file(GLOB SRC_FILES "src/*.cpp")

add_executable(tic-tac-toe ${SRC_FILES})

target_compile_options(tic-tac-toe
    PRIVATE
    $<$<CONFIG:Debug>:-O0;-g;-Wall;-Wextra>
    $<$<CONFIG:Release>:-O2;-Wall;-Wextra>
)

set(CMAKE_BUILD_TYPE Debug)