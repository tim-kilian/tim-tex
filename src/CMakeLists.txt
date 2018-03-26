link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(TimTex
		main.cpp
		gui/Application.cpp gui/Application.h
		gui/MainWindow.cpp gui/MainWindow.h
		gui/MenuBar.cpp gui/MenuBar.h gui/Preview.cpp gui/Preview.h gui/Console.cpp gui/Console.h gui/Editor.cpp gui/Editor.h gui/ProjectTree.cpp gui/ProjectTree.h)

target_link_libraries(TimTex ${GTKMM_LIBRARIES})
