cmake_minimum_required(VERSION 3.20)

function(MAKE_TEST test_name file)
    add_executable(${test_name} ${file})

    target_include_directories(${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)
    target_link_directories(${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
    target_link_libraries(${test_name} PRIVATE gtest)

    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

MAKE_TEST("mytest" ttest.cpp)
MAKE_TEST("XDDTEST" xddtest.cpp)