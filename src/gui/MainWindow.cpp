
#include <iostream>
#include <gtkmm/box.h>
#include <gtkmm/separator.h>
#include <gtkmm/alignment.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/paned.h>
#include <gtkmm/button.h>
#include "MainWindow.h"
#include "ProjectTree.h"
#include "MenuBar.h"
#include "ToolBar.h"

MainWindow::MainWindow() : editor(), console(), preview() {
    set_default_size(1200, 800);

    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);


    vbox->pack_start(*(new MenuBar(this)), Gtk::PACK_SHRINK);
    vbox->pack_start(*(new ToolBar(this)), Gtk::PACK_SHRINK);
    vbox->pack_start(*(new Gtk::Separator()), Gtk::PACK_SHRINK);
    vbox->pack_start(*create_view_main(), Gtk::PACK_EXPAND_WIDGET);
    vbox->pack_start(*(new Gtk::Separator()), Gtk::PACK_SHRINK);
    vbox->pack_end(*create_view_status_bar(), Gtk::PACK_SHRINK);

    add(*vbox);
    vbox->show_all();

    editor.open_file("/home/tim/LatexProjects/test/helloworld.tex");
    preview.set_file("/home/tim/LatexProjects/test/helloworld.pdf");
}

Gtk::Box* MainWindow::create_view_main() {
    auto hpaned = new Gtk::HPaned();

    auto project_tree = new ProjectTree(this);
    hpaned->add1(*project_tree);
    project_tree->open("/home/tim/LatexProjects/test");

    hpaned->add2(editor);

    hpaned->set_position(300);

    auto vpaned = new Gtk::VPaned();
    vpaned->add1(*hpaned);
    vpaned->add2(console);

    vpaned->set_position(650);

    auto paned = new Gtk::HPaned();
    paned->add1(*vpaned);
    paned->add2(preview);

    paned->set_position(800);

    auto box = new Gtk::Box();
    box->pack_start(*paned);

    return box;
}

Gtk::Box* MainWindow::create_view_status_bar() {
    auto hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);

    hbox->set_border_width(5);
    hbox->pack_start(*(new Gtk::Label("// Some Information")), Gtk::PACK_SHRINK);

    return hbox;
}
