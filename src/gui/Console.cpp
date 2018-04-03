
#include <gtkmm/label.h>
#include "Console.h"

Console::Console() : text_view(), console_window() {
    set_orientation(Gtk::ORIENTATION_VERTICAL);
    pack_start(*(new Gtk::Label("<_")), Gtk::PACK_SHRINK);
    auto console_window = new Gtk::ScrolledWindow();
    console_window->add(text_view);
    pack_start(*console_window, Gtk::PACK_EXPAND_WIDGET);
}

void Console::push_out(std::ifstream out) {
    out.seekg(0, std::ios::end);
    int len = static_cast<int>(out.tellg()) - 1;
    auto ret = new char[len];
    out.seekg(0, std::ios::beg);
    out.read(ret, len+1);
    push_out(ret);
    out.close();
}

void Console::push_out(const char* out) {
    text_view.get_buffer()->insert(text_view.get_buffer()->end(), "$> ");
    text_view.get_buffer()->insert(text_view.get_buffer()->end(), out);
    auto adjustment = console_window.get_vadjustment();
    adjustment->set_value(adjustment->get_upper() - adjustment->get_page_size());
}
