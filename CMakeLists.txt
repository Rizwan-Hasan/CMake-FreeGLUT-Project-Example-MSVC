cmake_minimum_required(VERSION 3.0.0)
project(Work VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(Work main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

INCLUDE_DIRECTORIES(
    ${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/freeglut/include"
)

LINK_DIRECTORIES(
    ${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/freeglut/lib"
)

TARGET_LINK_LIBRARIES(
    ${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/freeglut/lib/freeglut.lib"
)

add_custom_target(copy-files ALL
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/freeglut/bin/freeglut.dll
    ${CMAKE_CURRENT_BINARY_DIR}/Debug
)