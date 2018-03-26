
#ifndef TIMTEX_MAINWINDOW_H
#define TIMTEX_MAINWINDOW_H

#include <gtkmm/window.h>
#include "Editor.h"
#include "Console.h"
#include "ProjectTree.h"
#include "Preview.h"

class MainWindow : public Gtk::Window {
public:
    MainWindow();

private:
    Editor* editor;
    Console* console;
    ProjectTree* projectTree;
    Preview* preview;

    Gtk::Box* create_header_view();
    Gtk::Box* create_main_view();
    Gtk::Box* create_footer_view();
};


#endif
