
#ifndef TIMTEX_MAINWINDOW_H
#define TIMTEX_MAINWINDOW_H

#include <gtkmm/window.h>
#include "Editor.h"
#include "Console.h"
#include "Preview.h"

class MainWindow : public Gtk::Window {
public:
    MainWindow();

    Editor* getEditor() { return &editor; };
    Preview* getPreview() { return &preview; };
    Console* getConsole() { return &console; };

private:
    Gtk::Box* create_view_main();
    Gtk::Box* create_view_status_bar();

    Editor editor;
    Preview preview;
    Console console;
};


#endif
