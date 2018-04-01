link_directories(${GTKMM_LIBRARY_DIRS})
link_directories(${POPPL_LIBRARY_DIRS})
link_directories(${CAIRO_LIBRARY_DIRS})
link_directories(${PANGO_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(${POPPL_INCLUDE_DIRS})
include_directories(${CAIRO_INCLUDE_DIRS})
include_directories(${PANGO_INCLUDE_DIRS})

add_executable(TimTex
		main.cpp
		gui/Application.cpp gui/Application.h
		gui/MainWindow.cpp gui/MainWindow.h
		gui/MenuBar.cpp gui/MenuBar.h gui/Preview.cpp gui/Preview.h gui/Console.cpp gui/Console.h gui/Editor.cpp gui/Editor.h gui/ProjectTree.cpp gui/ProjectTree.h gui/ToolBar.cpp gui/ToolBar.h gui/EditorWindow.cpp gui/EditorWindow.h)

target_link_libraries(TimTex ${GTKMM_LIBRARIES})
target_link_libraries(TimTex ${POPPL_LIBRARIES})
target_link_libraries(TimTex ${CAIRO_LIBRARIES})
target_link_libraries(TimTex ${PANGO_LIBRARIES})
