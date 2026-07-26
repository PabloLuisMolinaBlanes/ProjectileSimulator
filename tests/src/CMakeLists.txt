include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_TAG v1.17.0
    GIT_REPOSITORY https://github.com/google/googletest.git
    FIND_PACKAGE_ARGS 1.17.0 NAMES GTest COMPONENTS gmain_main
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(googletest)
add_subdirectory(phys_functions_tests)
add_subdirectory(phys_engine_tests)