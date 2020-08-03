cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE FQL_TEST_FILES "*.cpp")

add_executable(FqlTest ${FQL_TEST_FILES})

target_include_directories(FqlTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(FqlTest FqlCoreLib)

set_property(TARGET FqlTest PROPERTY CXX_STANDARD 17)
