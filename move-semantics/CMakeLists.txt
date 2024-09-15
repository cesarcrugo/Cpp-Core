cmake_minimum_required(VERSION 3.22.1)
project (movesemantics)

include_directories(include)

add_executable(lrvalues l-rvalues.cpp)
target_include_directories(lrvalues PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lrvalues)

add_executable(movesemantics move-semantics.cpp)
target_include_directories(movesemantics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(movesemantics)