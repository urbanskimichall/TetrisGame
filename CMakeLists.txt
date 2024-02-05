cmake_minimum_required(VERSION 3.22)
project(tetris)

set(CMAKE_CXX_STANDARD 17)

include(cmake/UpdateSubmodules.cmake)
include(CTest)

add_subdirectory(external)
add_subdirectory(tests)

add_executable(tetris main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC external/SFML/include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-audio
        sfml-graphics
        sfml-network
        sfml-system
        sfml-window
)



