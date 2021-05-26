cmake_minimum_required(VERSION 3.19.0)

set (This "ExampleSetup")

project(${This} C CXX)
file (MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/output
    ${CMAKE_CURRENT_SOURCE_DIR}/build/output/bin
    ${CMAKE_CURRENT_SOURCE_DIR}/build/output/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/build/output/lib
    )

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/output)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_INCLUDE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/inc)

set(CMAKE_OUTPUT_DIR ${CMAKE_BINARY_DIR})

set(PROJECTLIB ExampleLib)
# set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
#set(CMAKE_CXX_STANDARD 17)
enable_testing()

include(src.cmake)
include(tests.cmake)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

aux_source_directory(
    ${CMAKE_CURRENT_SOURCE_DIR}/ PROJECTMAINFILE
)

link_directories(
    ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}   
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}   
)


add_executable(
    ${This}
    ${PROJECTMAINFILE}
)

target_link_libraries(${This}
    ${PROJECTLIB}
)

