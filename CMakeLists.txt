cmake_minimum_required(VERSION 3.28)

project(ChessX3D VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

add_subdirectory(thirdparty/glfw-3.4)
add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/stb_image)
add_subdirectory(thirdparty/imgui)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(GAME_ICON ${CMAKE_CURRENT_SOURCE_DIR}/resources/ChessX3D.icns)

set_source_files_properties(${GAME_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
set(MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/resources/Info.plist)

add_executable("${CMAKE_PROJECT_NAME}")

set_target_properties("${CMAKE_PROJECT_NAME}" PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_INFO_PLIST ${MACOSX_BUNDLE_INFO_PLIST}
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}"
)

target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${MY_SOURCES} ${GAME_ICON})
target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC GLFW_INCLUDE_NONE=1 GL_SILENCE_DEPRECATION GLM_ENABLE_EXPERIMENTAL)
target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE "-framework Cocoa" "-framework OpenGL" "-framework IOKit" glm glfw glad stb_image imgui)