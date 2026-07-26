include_directories(include)
add_library(physics_functions physics_functions.cpp)
target_include_directories(physics_functions
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)