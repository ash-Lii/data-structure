cmake_minimum_required(VERSION 3.10)
project(DataStructureLearning)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags for better debugging and warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

# Include directories
include_directories(include)

# Create library for data structures
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(data_structures ${SOURCES})

# Create examples executables
add_executable(array_example examples/array_example.cpp)
target_link_libraries(array_example data_structures)

add_executable(linked_list_example examples/linked_list_example.cpp)
target_link_libraries(linked_list_example data_structures)

add_executable(stack_example examples/stack_example.cpp)
target_link_libraries(stack_example data_structures)

add_executable(queue_example examples/queue_example.cpp)
target_link_libraries(queue_example data_structures)

add_executable(binary_tree_example examples/binary_tree_example.cpp)
target_link_libraries(binary_tree_example data_structures)

add_executable(hash_table_example examples/hash_table_example.cpp)
target_link_libraries(hash_table_example data_structures)