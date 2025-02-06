cmake_minimum_required(VERSION 3.27)

project(GameEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(GameEngineConfig.h.in GameEngineConfig.h)
add_executable(GameEngine main.cpp GameEngine.cpp)

add_subdirectory(glad)

add_library(GLFW STATIC IMPORTED)
set_target_properties(GLFW PROPERTIES
    IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/glfw/libglfw3.a"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/glfw"
)

target_link_libraries(GameEngine PUBLIC GLAD GLFW)

find_library(COCOA_LIBRARY Cocoa REQUIRED)
find_library(OPENGL_LIBRARY OpenGL REQUIRED)
find_library(IOKIT_LIBRARY IOKit REQUIRED)

target_link_libraries(GameEngine PRIVATE
    ${COCOA_LIBRARY} ${OPENGL_LIBRARY} ${IOKIT_LIBRARY}
)

target_include_directories(GameEngine PUBLIC 
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/glad"
                            "${PROJECT_SOURCE_DIR}/includes"
                            )