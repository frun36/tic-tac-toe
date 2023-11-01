# Set the project and target names
set(PROJECT_NAME "Tic-Tac-Toe")
set(TARGET_NAME "tic-tac-toe")

# Prevent in-source building
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

# Set CMake version and C++ standard
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 11)

# Set the project name and version
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

# Specify path to include directory
include_directories(include)

# Get all source .cpp files and add them to the executable target
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
list(FILTER SRC_FILES EXCLUDE REGEX "main.cpp$")
add_executable(${TARGET_NAME} ${SRC_FILES} "src/main.cpp")

# Set compiler flags based on build type
target_compile_options(${TARGET_NAME}
    PRIVATE
    $<$<CONFIG:Debug>:-O0;-g;-Wall;-Wextra>
    $<$<CONFIG:Release>:-O2;-Wall;-Wextra>
)

# Set default build type to `Debug`
set(CMAKE_BUILD_TYPE Debug)

# Enable CTest
enable_testing()

# Add memory test with Valgrind
add_test(
    NAME mem
    COMMAND valgrind --leak-check=full --track-origins=yes --error-exitcode=1 ./${TARGET_NAME}
)

# Add unit tests
file(GLOB_RECURSE TEST_FILES "tests/*.cpp")
foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE} ${SRC_FILES})
    add_test(NAME ${TEST_NAME} COMMAND ./${TEST_NAME})
endforeach()

# Build Doxygen documentation
find_package(Doxygen)
if(NOT DOXYGEN_FOUND)
    message(ERROR "Doxygen not found")
else()
    # Set Doxygen config
    set(DOXYGEN_INPUT_DIR "${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include")
    set(DOXYGEN_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/docs")    

    # Configure the Doxyfile
    configure_file(doxyfile.in doxyfile @ONLY)

    # Add a target to generate Doxygen documentation
    add_custom_target(
        doc
        COMMAND ${DOXYGEN_EXECUTABLE} doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating Doxygen documentation"
        VERBATIM
    )
endif()
