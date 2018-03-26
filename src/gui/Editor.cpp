//
// Created by tim on 3/27/18.
//

#include <gtkmm/notebook.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/separator.h>
#include <gtkmm/alignment.h>
#include <gtkmm/box.h>
#include "Editor.h"

Editor::Editor() {
    auto hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);

    hbox->pack_start(*create_line_number_view(100), Gtk::PACK_SHRINK);
    hbox->pack_start(*(new Gtk::Separator()), Gtk::PACK_SHRINK);

    hbox->pack_start(*(new Gtk::TextView()), Gtk::PACK_EXPAND_WIDGET);

    auto editorWindow = new Gtk::ScrolledWindow();
    editorWindow->set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
    editorWindow->add(*hbox);

    auto notebook = new Gtk::Notebook();
    notebook->append_page(*editorWindow, "First");
    notebook->signal_switch_page().connect(sigc::mem_fun(*this, &Editor::on_switch_tab));

    pack_start(*notebook, Gtk::PACK_EXPAND_WIDGET);
}

Gtk::Widget* Editor::create_line_number_view(int lines) {
    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

    for (int i=1; i<=lines; i++) {
        auto alignment = new Gtk::Alignment(Gtk::ALIGN_END);
        alignment->add(*(new Gtk::Label(std::to_string(i))));
        vbox->pack_start(*alignment, Gtk::PACK_SHRINK);
    }

    return vbox;
}

void Editor::on_switch_tab(Gtk::Widget* tab, int page) {

}