cmake_minimum_required(VERSION 3.19.0)

set(PROJECTLIBTESTS SnakeFightTests)

link_directories(
    ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}   
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}   
)

include_directories(
)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/test PROJECTLIBTESTSRC)

add_executable(${PROJECTLIBTESTS} ${PROJECTLIBTESTSRC})

target_link_libraries(${PROJECTLIBTESTS} PUBLIC
    gtest_main
    gtest.a
    pthread
    ${PROJECTLIB}
    )

add_test(
    NAME ${PROJECTLIBTESTS}
    COMMAND ${PROJECTLIBTESTS}
)