FILE(GLOB_RECURSE HEADERS "src/*.hpp" "src/*.h")
FILE(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(NewtonFramework_Example
        ${SOURCES}
        ${HEADERS})

target_include_directories(NewtonFramework_Example
        PRIVATE
        "${CMAKE_SOURCE_DIR}/src/"
)

target_link_libraries(NewtonFramework_Example
        PRIVATE
        NewtonFramework
        imgui::imgui)