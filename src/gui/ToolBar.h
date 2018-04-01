
#ifndef TIMTEX_TOOLBAR_H
#define TIMTEX_TOOLBAR_H


#include <gtkmm/box.h>
#include "MainWindow.h"

class ToolBar : public Gtk::Box {

public:
    explicit ToolBar(MainWindow* window);

private:
    MainWindow* parent;

    void on_compile();
};


#endif
