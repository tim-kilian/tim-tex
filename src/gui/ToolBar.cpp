//
// Created by tim on 3/30/18.
//

#include "ToolBar.h"
#include <gtkmm/button.h>
#include <iostream>
#include <fstream>

ToolBar::ToolBar(MainWindow* window) : parent(window) {
    set_border_width(10);

    auto breadcrumb = new Gtk::Label("Project / Breadcrumb");
    pack_start(*breadcrumb, false, true);

    auto next = new Gtk::Button("Next");
    next->signal_clicked().connect(sigc::mem_fun(parent->getPreview(), &Preview::on_increase_page));
    pack_end(*next, Gtk::PACK_SHRINK);
    auto prev = new Gtk::Button("Prev");
    prev->signal_clicked().connect(sigc::mem_fun(parent->getPreview(), &Preview::on_decrease_page));
    pack_end(*prev, Gtk::PACK_SHRINK);
    auto compile = new Gtk::Button("Compile");
    compile->signal_clicked().connect(sigc::mem_fun(*this, &ToolBar::on_compile));
    pack_end(*compile, Gtk::PACK_SHRINK);

}

void ToolBar::on_compile() {
    system("pdflatex --output-directory /home/tim/LatexProjects/test /home/tim/LatexProjects/test/helloworld.tex > /home/tim/LatexProjects/test/helloworld.out");
    parent->getPreview()->update();
    parent->getConsole()->push_out(std::ifstream("/home/tim/LatexProjects/test/helloworld.out"));
}
