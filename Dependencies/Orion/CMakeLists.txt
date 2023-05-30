cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(Orion
    LANGUAGES C CXX
    DESCRIPTION "A raylib front-end used in Undyne's Target Practice."
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_LIST_DIR}/CMake")

set(ORION_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/Source")
set(ORION_SOURCES
    "${ORION_SOURCE_DIR}/GameObject.cpp"
    "${ORION_SOURCE_DIR}/Sprite.cpp"
    "${ORION_SOURCE_DIR}/Object.cpp"
    "${ORION_SOURCE_DIR}/Scene.cpp"
    "${ORION_SOURCE_DIR}/SceneCollection.cpp"
)

#Adding the dependencies
set(DEPENDENCY_DIR "${CMAKE_CURRENT_LIST_DIR}/Dependencies/Third-Party")
include(GetDependencies)

add_library(${PROJECT_NAME} ${ORION_SOURCES})

set(ORION_INCLUDE_DIR "${ORION_SOURCE_DIR}/Include")
set(RAYLIB_INCLUDE_DIR "${DEPENDENCY_DIR}/raylib-4.5.0/src")
set(RAYLIB_CPP_INCLUDE_DIR "${DEPENDENCY_DIR}/raylib-cpp-4.5.0/include")

target_include_directories(${PROJECT_NAME}
        
    PUBLIC
        "${RAYLIB_INCLUDE_DIR}"
        "${RAYLIB_CPP_INCLUDE_DIR}"
        "${ORION_INCLUDE_DIR}"
        
)


if (WIN32)
    target_link_libraries(${PROJECT_NAME} PUBLIC
        
        "-lopengl32"
        "-lgdi32"
        "-lwinmm"
    )
elseif (APPLE)
    target_link_libraries(${PROJECT_NAME} PUBLIC
        "-framework IOKit"
        "-framework Cocoa"
        "-framework OpenGL"
    )
elseif (LINUX)
    target_link_libraries(${PROJECT_NAME} PUBLIC
        "-lGL"
        "-lm"
        "-lpthread"
        "-ldl"
        "-lrt"
        "-lX11"
        raylib
    )
endif()