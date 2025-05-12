# Minimum CMake version required
cmake_minimum_required(VERSION 3.14)

# Set the project name
project(BiffTifr VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Use FetchContent to get jsoncpp from GitHub
include(FetchContent)

FetchContent_Declare(
    jsoncpp
    GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
    GIT_TAG        1.9.5  # Use a specific stable release
)

# Pull in the content and make it available
FetchContent_MakeAvailable(jsoncpp)

# Collect all source files (adjust as needed)
file(GLOB UI_SOURCES     ${CMAKE_SOURCE_DIR}/ui/*.cpp)
file(GLOB TASK_SOURCES   ${CMAKE_SOURCE_DIR}/task/*.cpp)
file(GLOB SAVE_SOURCES   ${CMAKE_SOURCE_DIR}/save/*.cpp)

set(SOURCE_FILES
    ${UI_SOURCES}
    ${TASK_SOURCES}
    ${SAVE_SOURCES}
)

# Define the executable
add_executable(bifftifr ${SOURCE_FILES})

# Link jsoncpp and include headers
target_link_libraries(bifftifr PRIVATE jsoncpp_lib)

# Add your project-specific include directories
target_include_directories(bifftifr
    PRIVATE
        ${CMAKE_SOURCE_DIR}/ui
        ${CMAKE_SOURCE_DIR}/task
        ${CMAKE_SOURCE_DIR}/save
)

# Optionally add debug/release flags here
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

# Display a success message
message(STATUS "BiffTifr is configured and ready to build with jsoncpp 🎉")
