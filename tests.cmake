cmake_minimum_required(VERSION 3.19.0)

set(PROJECTLIBTESTS ExampleTests)
set(GOOGLETEST_DIR E:/Learning/googleTestInstall/)

link_directories(
    ${GOOGLETEST_DIR}/lib
    ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}   
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}   
)

include_directories(
    ${GOOGLETEST_DIR}/include
)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/test PROJECTLIBTESTSRC)

add_executable(${PROJECTLIBTESTS} ${PROJECTLIBTESTSRC})

target_link_libraries(${PROJECTLIBTESTS} PUBLIC
    gtest_main
    gtest
    ${PROJECTLIB}
    )

add_test(
    NAME ${PROJECTLIBTESTS}
    COMMAND ${PROJECTLIBTESTS}
)