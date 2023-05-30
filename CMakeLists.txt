cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(
    Undynes-Target-Practice
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "UNDERTALE™ Undyne's Target Practice, you're goal is to survive as long as possible while Undyne is throws spears and you from all directions. "
)


set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_LIST_DIR}/CMake")

#Adding the dependencies
set(DEPENDENCY_DIR "${CMAKE_CURRENT_LIST_DIR}/Dependencies")
add_subdirectory("${DEPENDENCY_DIR}/Orion")

set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/Source")
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS 
    "${PROJECT_SOURCE_DIR}/*.c"
    "${PROJECT_SOURCE_DIR}/*.h"
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.hpp"
)

set(PROJECT_ASSETS_DIR "${CMAKE_CURRENT_LIST_DIR}/Assets")
include(GetAssets)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_ASSETS})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Orion
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${DEPENDENCY_DIR}/Orion/Include"
)


if (NOT ${CMAKE_BUILD_TYPE} STREQUAL "Debug")

    include(MakeAppBundle)

else()

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD 
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/Resources"
    
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy ${RAYLIB_LIBS} "${CMAKE_BINARY_DIR}"
    #COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_ASSETS} "${CMAKE_BINARY_DIR}/Resources"
)



endif()