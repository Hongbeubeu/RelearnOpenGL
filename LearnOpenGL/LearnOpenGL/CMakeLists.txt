cmake_minimum_required(VERSION 3.28)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 11)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ASSIMP_INJECT_DEBUG_POSTFIX OFF CACHE BOOL "" FORCE)
set(ASSIMP_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw-3.4)
add_subdirectory(assimp)
include_directories(.)
include_directories(include)
include_directories(assimp/include)
include_directories(backpack)

find_package(OpenGL REQUIRED)

add_executable(LearnOpenGL window.cpp glad.c shader.cpp stb_image.cpp camera.cpp
        mesh.cpp
        mesh.hpp
        model.h
)
target_link_libraries(LearnOpenGL OpenGL::GL)
target_link_libraries(LearnOpenGL glfw)
target_link_libraries(LearnOpenGL assimp::assimp)
