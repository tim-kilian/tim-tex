
#ifndef TIMTEX_MENUBAR_H
#define TIMTEX_MENUBAR_H

#include <gtkmm/menubar.h>
#include <gtkmm/menu.h>
#include "MainWindow.h"

class MenuBar : public Gtk::MenuBar {

public:
    explicit MenuBar(MainWindow* window);

private:
    Gtk::MenuItem* create_menu_file();
    Gtk::MenuItem* create_menu_edit();
    Gtk::MenuItem* create_menu_view();
    Gtk::MenuItem* create_menu_document();
    Gtk::MenuItem* create_menu_help();

    Gtk::Menu* menu_file;
    Gtk::Menu* menu_edit;
    Gtk::Menu* menu_view;
    Gtk::Menu* menu_document;
    Gtk::Menu* menu_vcs;
    Gtk::Menu* menu_help;

    Gtk::MenuItem* create_menu_vcs();

    MainWindow* parent;

    void on_next_page();
};


#endif
