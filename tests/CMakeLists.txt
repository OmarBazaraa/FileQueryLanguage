cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE FQL_TEST_FILES "*.cpp")

add_executable(FQL_TEST ${FQL_TEST_FILES})

target_include_directories(FQL_TEST PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(FQL_TEST FQL_CORE_LIB)

set_property(TARGET FQL_TEST PROPERTY CXX_STANDARD 17)
