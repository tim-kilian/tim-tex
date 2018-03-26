
#include <iostream>
#include <gtkmm/box.h>
#include <gtkmm/separator.h>
#include <gtkmm/alignment.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/paned.h>
#include "MainWindow.h"
#include "MenuBar.h"

MainWindow::MainWindow() {
    set_default_size(1200, 800);

    editor = new Editor();
    console = new Console();
    projectTree = new ProjectTree();
    preview = new Preview();

    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

    vbox->pack_start(*(new MenuBar()), Gtk::PACK_SHRINK);
    vbox->add(*create_header_view());
    vbox->add(*(new Gtk::Separator()));
    vbox->pack_start(*create_main_view(), Gtk::PACK_EXPAND_WIDGET);
    vbox->add(*(new Gtk::Separator()));
    vbox->pack_end(*create_footer_view(), Gtk::PACK_SHRINK);

    add(*vbox);
    vbox->show_all();
}

Gtk::Box* MainWindow::create_header_view() {
    auto hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
    hbox->set_border_width(10);

    auto breadcrumb = new Gtk::Label("Project / Breadcrumb");
    hbox->pack_start(*breadcrumb, Gtk::PACK_SHRINK);

    return hbox;
}

Gtk::Box* MainWindow::create_main_view() {
    auto hpaned = new Gtk::HPaned();
    hpaned->add1(*projectTree);
    hpaned->add2(*editor);

    hpaned->set_position(300);

    auto vpaned = new Gtk::VPaned();
    vpaned->add1(*hpaned);
    vpaned->add2(*console);

    vpaned->set_position(650);

    auto paned = new Gtk::HPaned();
    paned->add1(*vpaned);
    paned->add2(*preview);

    paned->set_position(800);

    auto box = new Gtk::Box();
    box->pack_start(*paned);

    return box;
}

Gtk::Box* MainWindow::create_footer_view() {
    auto hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);

    hbox->set_border_width(5);
    hbox->pack_start(*(new Gtk::Label("// Some Information")), Gtk::PACK_SHRINK);

    return hbox;
}
