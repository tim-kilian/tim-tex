
#ifndef TIMTEX_FILE_H
#define TIMTEX_FILE_H


#include <gtkmm/box.h>
#include <gtkmm/textview.h>

class EditorWindow : public Gtk::Box {

public:
    explicit EditorWindow(const char* path);

    std::string get_title();

private:
    const char* filepath;

    Gtk::TextView text_view;
    Gtk::Box line_numbers;
    int current_line_number = -1;

    void update_line_numbers();
    void on_changed();


    void save();

    sigc::connection typing_input;
    bool typed_input(int timer);
};


#endif
