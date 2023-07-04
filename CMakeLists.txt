cmake_minimum_required(VERSION 3.25)

project(TOBENAMED LANGUAGES CXX)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -Wextra -pedantic -Wwrite-strings -Wstrict-prototypes")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(CheckIPOSupported)
check_ipo_supported(RESULT supported OUTPUT error)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/main.cpp src/Game/MainGame.cpp include/Game/MainGame.h src/Game/Sprite.cpp include/Game/Sprite.h)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} GLEW::GLEW)

# For lto
if(supported)
    message(STATUS "IPO / LTO enabled")
    set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
    message(STATUS "IPO / LTO not supported: <${error}>")
endif()