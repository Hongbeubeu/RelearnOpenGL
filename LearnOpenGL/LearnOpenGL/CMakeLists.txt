cmake_minimum_required(VERSION 3.28)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 11)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw-3.4)
include_directories(.)
include_directories(include)

find_package(OpenGL REQUIRED)

add_executable(LearnOpenGL window.cpp glad.c shader.cpp stb_image.cpp camera.cpp)
target_link_libraries(LearnOpenGL OpenGL::GL)
target_link_libraries(LearnOpenGL glfw)
