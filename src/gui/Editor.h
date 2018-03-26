
#ifndef TIMTEX_EDITOR_H
#define TIMTEX_EDITOR_H


class Editor : public Gtk::Box {

public:
    Editor();

private:
    Gtk::Widget* create_line_number_view(int lines);

protected:
    void on_switch_tab(Gtk::Widget* tab, int page);
};


#endif
