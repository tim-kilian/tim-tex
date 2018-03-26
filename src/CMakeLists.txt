link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(TimTex
		main.cpp
		ui/Application.cpp ui/Application.h
		ui/MainWindow.cpp ui/MainWindow.h
		ui/MenuBar.cpp ui/MenuBar.h)

target_link_libraries(TimTex ${GTKMM_LIBRARIES})
