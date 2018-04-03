
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/separator.h>
#include <gtkmm/alignment.h>
#include <gtkmm/button.h>
#include <gtkmm/image.h>
#include <gtkmm/stock.h>
#include <set>
#include "Editor.h"
#include "EditorWindow.h"

Editor::Editor() : notebook() {
    pack_start(notebook, Gtk::PACK_EXPAND_WIDGET);

    notebook.signal_switch_page().connect(sigc::mem_fun(*this, &Editor::on_switch_tab));
}

void Editor::open_file(const char* path) {
    std::vector<std::string> spath = splitpath(path);

    auto editor = new EditorWindow(path);
    notebook.set_current_page(notebook.append_page(*editor));
    notebook.set_tab_label(*editor, *create_tab_label(spath.back().c_str()));
    notebook.set_tab_reorderable(*editor);
    // notebook.set_tab_detachable(*window);
}

Gtk::Box* Editor::create_tab_label(const char* title) {
    auto hbox = new Box(Gtk::ORIENTATION_HORIZONTAL);
    hbox->set_spacing(0);

    auto label = new Gtk::Label(title);
    auto button = new Gtk::Button();
    button->set_image(*(new Gtk::Image(Gtk::Stock::CLOSE, Gtk::BuiltinIconSize::ICON_SIZE_MENU)));
    button->set_tooltip_text("close.");
    button->set_relief(Gtk::ReliefStyle::RELIEF_NONE);
    button->set_focus_on_click(false);
    button->signal_clicked().connect(sigc::mem_fun(*this, &Editor::on_close_tab));

    hbox->pack_start(*label, Gtk::PACK_SHRINK);
    hbox->pack_start(*button, Gtk::PACK_SHRINK);

    hbox->show_all();
    return hbox;
}

void Editor::on_switch_tab(Gtk::Widget* tab, int page) {

}

std::vector<std::string> Editor::splitpath(const std::string& str) {
    std::set<char> delimiters{'/', '\\'};

    std::vector<std::string> result;

    char const* pch = str.c_str();
    char const* start = pch;
    for(; *pch; ++pch) {
        if (delimiters.find(*pch) != delimiters.end()) {
            if (start != pch) {
                std::string string(start, pch);
                result.push_back(string);
            } else {
                result.emplace_back("");
            }
            start = pch + 1;
        }
    }
    result.emplace_back(start);

    return result;
}

void Editor::on_close_tab() {
    notebook.remove_page(notebook.get_current_page());
}
