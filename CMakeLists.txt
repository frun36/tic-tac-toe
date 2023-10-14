# Set the project and target names
set(PROJECT_NAME "Tic-Tac-Toe")
set(TARGET_NAME "tic-tac-toe")

# Set CMake version and C++ standard
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 11)

# Set the project name and version
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

# Specify path to include directory
include_directories(include)

# Get all source .cpp files and add them to the executable target
file(GLOB SRC_FILES "src/*.cpp")
add_executable(${TARGET_NAME} ${SRC_FILES})

# Set compiler flags based on build type
target_compile_options(${TARGET_NAME}
    PRIVATE
    $<$<CONFIG:Debug>:-O0;-g;-Wall;-Wextra>
    $<$<CONFIG:Release>:-O2;-Wall;-Wextra>
)

# Set default build type to `Debug`
set(CMAKE_BUILD_TYPE Debug)