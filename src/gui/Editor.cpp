
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/separator.h>
#include <gtkmm/alignment.h>
#include <set>
#include "Editor.h"
#include "EditorWindow.h"

Editor::Editor() : notebook() {
    pack_start(notebook, Gtk::PACK_EXPAND_WIDGET);

    notebook.signal_switch_page().connect(sigc::mem_fun(*this, &Editor::on_switch_tab));
}

void Editor::open_file(const char* path) {
    std::vector<std::string> spath = splitpath(path);
    notebook.append_page(*(new EditorWindow(path)), spath.back());
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
