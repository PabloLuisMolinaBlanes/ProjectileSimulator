include(FetchContent)
FetchContent_Declare(wxWidgets
	GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets/
	GIT_TAG v3.3.0
	GIT_SHALLOW ON
	EXCLUDE_FROM_ALL_SYSTEM
)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)

FetchContent_MakeAvailable(wxWidgets)
FetchContent_MakeAvailable(SFML)

add_executable(gui gui.cpp)
add_executable(sfml_window sfml_engine_window.cpp)
target_link_libraries(gui PRIVATE wx::net wx::core wx::base)
target_link_libraries(sfml_window PRIVATE SFML::Graphics)
target_link_libraries(sfml_window PRIVATE phys_engine)
