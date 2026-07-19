cmake_minimum_required(VERSION 3.28)
project(ballistics_simulator)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(wxWidgets
	GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets/
	GIT_TAG 3.3.0
	GIT_SHALLOW ON
	EXCLUDE_FROM_ALL_SYSTEM
)

FetchContent_MakeAvailable(wxWidgets)

add_executable(gui lib/gui.cpp)
target_link_libraries(gui PRIVATE wxWidgets)
