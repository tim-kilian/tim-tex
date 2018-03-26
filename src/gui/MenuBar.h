
#ifndef TIMTEX_MENUBAR_H
#define TIMTEX_MENUBAR_H

#include <gtkmm/menubar.h>
#include <gtkmm/menu.h>

class MenuBar : public Gtk::MenuBar {

public:
    MenuBar();

private:
    Gtk::MenuItem* create_menu_file();
    Gtk::MenuItem* create_menu_edit();
    Gtk::MenuItem* create_menu_view();
    Gtk::MenuItem* create_menu_help();

    Gtk::Menu* menu_file;
    Gtk::Menu* menu_edit;
    Gtk::Menu* menu_view;
    Gtk::Menu* menu_help;
};


#endif
