cmake_minimum_required(VERSION 3.20)
project(NewtonFramework)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_subdirectory(example)

add_library(${PROJECT_NAME} STATIC)

file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.hpp" "${CMAKE_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

target_sources(${PROJECT_NAME}
        PRIVATE
        ${SOURCES}
        ${HEADERS}
        PUBLIC
        "${CMAKE_SOURCE_DIR}/include/NewtonFramework.h"
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        glad::glad
        glfw
        GL
        glm::glm
        imgui::imgui
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)