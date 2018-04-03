//
// Created by tim on 3/31/18.
//

#include <iostream>
#include <fstream>
#include <gtkmm/separator.h>
#include <gtkmm/scrolledwindow.h>
#include <glibmm.h>
#include "EditorWindow.h"

const char* default_text = "\\documentclass{article}\n\n\\begin{document}\nhello world.\n\\end{document}\n";

EditorWindow::EditorWindow(const char* path) :
        filepath(path),
        text_view(),
        line_numbers(Gtk::ORIENTATION_VERTICAL),
        typing_input() {
    std::ifstream file(path);

    auto buffer = text_view.get_buffer();

    file.seekg(0, std::ios::end);
    int len = static_cast<int>(file.tellg());
    auto ret = new char[len-1];
    file.seekg(0, std::ios::beg);
    file.read(ret, len);
    buffer->set_text(ret);
    file.close();

    buffer->signal_changed().connect(sigc::mem_fun(*this, &EditorWindow::on_changed));

    update_line_numbers();

    auto editor = new Gtk::ScrolledWindow();
    editor->set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);

    auto hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
    hbox->pack_start(line_numbers, Gtk::PACK_SHRINK);
    hbox->pack_start(*(new Gtk::Separator()), Gtk::PACK_SHRINK);
    hbox->pack_start(text_view, Gtk::PACK_EXPAND_WIDGET);
    editor->add(*hbox);

    pack_start(*editor, Gtk::PACK_EXPAND_WIDGET);

    show_all();
}

void EditorWindow::update_line_numbers() {
    std::string text = text_view.get_buffer()->get_text();
    int lines = static_cast<int>(std::count(text.begin(), text.end(), '\n'));

    if (current_line_number != lines) {
        if (current_line_number < lines) {
            for (int i = current_line_number; i < lines; i++) {
                line_numbers.add(*(new Gtk::Label(std::to_string((i + 2)))));
            }
        } else if (current_line_number > lines) {
            for (int i = current_line_number; i > lines; i--) {
                line_numbers.remove(*(line_numbers.get_children().at(static_cast<unsigned long>(i))));
            }
        }

        line_numbers.show_all();
        current_line_number = lines;
    }
}

void EditorWindow::save() {
    std::ofstream outfile(filepath);

    auto buffer = text_view.get_buffer();

    outfile << buffer->get_text();
}

void EditorWindow::on_changed() {
    update_line_numbers();

    typing_input.disconnect();
    typing_input = Glib::signal_timeout().connect(sigc::bind(sigc::mem_fun(*this, &EditorWindow::typed_input), 0), 1000);
}

bool EditorWindow::typed_input(int) {
    save();
    return false;
}

std::string EditorWindow::get_title() {
    return std::__cxx11::string();
}
