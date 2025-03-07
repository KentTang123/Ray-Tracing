cmake_minimum_required(VERSION 3.20)

project(Ray-Tracing VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    src/core/main.cpp
    src/core/application.cpp
)

add_subdirectory(ext)

target_include_directories(${PROJECT_NAME} PRIVATE ${Include-dir} ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_directories(${PROJECT_NAME} PRIVATE ${Lib-dir})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Libs})

enable_testing()
add_subdirectory(test)

foreach(file IN LISTS DLL-FILE)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to MyTest
        COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        ${file}    
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "copying dll file"
    )    
endforeach()
