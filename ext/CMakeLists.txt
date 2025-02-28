cmake_minimum_required(VERSION 3.20)

set(Include-dir ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)
set(Lib-dir ${CMAKE_CURRENT_SOURCE_DIR}/lib PARENT_SCOPE)
set(Libs 
    imgui
    glfw3
    vulkan-1
    assimp-vc143-mtd
    PARENT_SCOPE
)

set(DLL-FILE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/assimp-vc143-mtd.dll
    PARENT_SCOPE
)

add_library(imgui STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui_impl_vulkan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui.cpp
)

target_include_directories(imgui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_directories(imgui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(imgui PRIVATE glfw3 vulkan-1)