cmake_minimum_required(VERSION 3.28)
project(imgui)

set(CMAKE_CXX_STANDARD 11)

add_library(imgui)
target_sources(imgui PRIVATE 
"imgui/imgui.cpp"
"imgui/imgui_demo.cpp"
"imgui/imgui_draw.cpp"
"imgui/imgui_tables.cpp"
"imgui/imgui_widgets.cpp"
"imgui/backends/imgui_impl_glfw.cpp"
"imgui/backends/imgui_impl_opengl3.cpp"
)

target_include_directories(imgui PUBLIC "imgui")
target_link_libraries(imgui PUBLIC glfw glad)