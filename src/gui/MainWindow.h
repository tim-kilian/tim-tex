
#ifndef TIMTEX_MAINWINDOW_H
#define TIMTEX_MAINWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <gtkmm/textview.h>
#include <gtkmm/notebook.h>
#include <gtkmm/treeview.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow();

private:
    Gtk::Notebook* notebook;
    Gtk::TreeView* treeView;
    Gtk::TextView* textView;
    Gtk::Label* breadcrumb;

    Gtk::Box* create_header_view();
    Gtk::Box* create_main_view();
    Gtk::Box* create_project_view();
    Gtk::Box* create_line_number_view(int lines);
    Gtk::Box* create_editor_view();
    Gtk::Box* create_console_view();
    Gtk::Box* create_document_view();
    Gtk::Box* create_footer_view();

    void on_switch_tab(Gtk::Widget* tab, int page);

    void on_button_drag_data_get(const Glib::RefPtr<Gdk::DragContext>& context, Gtk::SelectionData& selection_data, guint info, guint time);
};


#endif
