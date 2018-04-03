
#ifndef TIMTEX_EDITOR_H
#define TIMTEX_EDITOR_H

#include <gdk/gdk.h>
#include <gtkmm/box.h>
#include <gtkmm/notebook.h>
#include <gtkmm/textview.h>

class Editor : public Gtk::Box {

public:
    Editor();
    void open_file(const char* path);

private:
    Gtk::Notebook notebook;

    Gtk::Box* create_tab_label(const char* title);
    std::vector<std::string> splitpath(const std::string &str);

protected:

    void on_switch_tab(Gtk::Widget* tab, int page);
    void on_close_tab();
};


#endif
