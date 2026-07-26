include_directories(${CMAKE_SOURCE_DIR}/src/phys_engine/include)
add_executable(phys_engine_tests phys_engine_tests.cpp)
target_link_libraries(phys_engine_tests PUBLIC GTest::gtest_main)
target_link_libraries(phys_engine_tests PUBLIC phys_engine)