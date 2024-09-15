cmake_minimum_required(VERSION 3.22.1)
project (Static)

include_directories(include)

add_executable(Static static.cpp static_.cpp main.cpp)
target_include_directories(Static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Static)