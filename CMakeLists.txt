cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(
    Undynes-Target-Practice
    LANGUAGES CXX
    DESCRIPTION "UNDERTALE™ Undyne's Target Practice, you're goal is to survive as long as possible while Undyne is throws spears and you from all directions. "
)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_LIST_DIR}/CMake")

#Adding the dependencies
set(DEPENDENCY_DIR "${CMAKE_CURRENT_LIST_DIR}/Dependencies/Third-Party")
include(AddRaylib)
include(AddRaylibCpp)

set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/Source")
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS 
    "${PROJECT_SOURCE_DIR}/*.c"
    "${PROJECT_SOURCE_DIR}/*.h"
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.hpp"
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    "${DEPENDENCY_DIR}/raylib-cpp-4.5.0/include"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib
)

set(PROJECT_ASSETS_DIR ${CMAKE_CURRENT_LIST_DIR}/Assets)
file(GLOB_RECURSE PROJECT_ASSETS 
    "${PROJECT_ASSETS_DIR}/*.wav"
    "${PROJECT_ASSETS_DIR}/*.ogg"
    "${PROJECT_ASSETS_DIR}/*.png"
    "${PROJECT_ASSETS_DIR}/*.jpg"
    "${PROJECT_ASSETS_DIR}/*.bmp"
)

if (NOT ${CMAKE_BUILD_TYPE} STREQUAL "Debug")

    include(MakeAppBundle)

else()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy ${RAYLIB_LIBS} "${CMAKE_BINARY_DIR}"
)

SET(CMAKE_INSTALL_RPATH “${ORIGIN}”)

endif()