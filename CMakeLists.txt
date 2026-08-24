cmake_minimum_required(VERSION 3.28)
project(projectile_simulator LANGUAGES C CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(TEST FALSE)

add_subdirectory(src)

if(TEST)
 add_subdirectory(tests)
endif()
