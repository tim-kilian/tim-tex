
#ifndef TIMTEX_CONSOLE_H
#define TIMTEX_CONSOLE_H


#include <gtkmm/box.h>
#include <gtkmm/textview.h>
#include <gtkmm/scrolledwindow.h>
#include <fstream>

class Console : public Gtk::Box {

public:
    Console();

    void push_out(std::ifstream out);
    void push_out(const char* out);
private:
    Gtk::TextView text_view;
    Gtk::ScrolledWindow console_window;
};


#endif
