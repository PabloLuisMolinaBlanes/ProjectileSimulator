include(FetchContent)
FetchContent_Declare(wxWidgets
	GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets/
	GIT_TAG v3.3.0
	GIT_SHALLOW ON
	EXCLUDE_FROM_ALL_SYSTEM
)

FetchContent_MakeAvailable(wxWidgets)

add_executable(gui gui.cpp)
target_link_libraries(gui PRIVATE wx::net wx::core wx::base)