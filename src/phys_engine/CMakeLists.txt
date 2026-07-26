include_directories(include)
add_library(phys_engine phys_engine.cpp)
target_link_libraries(phys_engine PRIVATE physics_functions)
target_include_directories(physics_functions
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)