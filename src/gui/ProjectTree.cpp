
#include <iostream>
#include <gtkmm/liststore.h>
#include <gtkmm/widget.h>
#include "ProjectTree.h"

/**
 * Use Gtk::TreeView::get_events
 * and Gtk::TreeView::set_events
 * to add the Gdk::2BUTTON_PRESS
 * event to the others received
 * by the treeview, and then connect
 * to the Gtk::TreeView::signal_event()
 * function to specifiy your callback function.
 * Then, within that callback,
 * determine which row was selected
 * and then open your window accordingly.
 */

ProjectTree::ProjectTree(MainWindow* window) : parent(window) {
    tree_view = new Gtk::TreeView();


    pack_start(*(new Gtk::Label("Project")), Gtk::PACK_SHRINK);
    pack_start(*tree_view, Gtk::PACK_EXPAND_WIDGET);

    tree_view->set_events(static_cast<Gdk::EventMask>(1 << 8));
    tree_view->signal_button_press_event().connect(sigc::mem_fun(*this, &ProjectTree::on_double_click));

    tree_model = Gtk::TreeStore::create(columns);
    tree_view->set_model(tree_model);
    tree_view->set_reorderable();

    tree_view->append_column("Project", columns.name);
}

void ProjectTree::open(const char* directory) {
    project_path = path(directory);

    auto project_row = *(tree_model->append());
    project_row[columns.name] = project_path.filename().generic_string();
    project_row[columns.filepath] = project_path.generic_string();

    for (directory_entry& x : directory_iterator(project_path)) {
        Gtk::TreeModel::Row row = *(tree_model->append(project_row.children()));
        row[columns.name] = x.path().filename().generic_string();
        row[columns.filepath] = x.path().generic_string();

    }

    tree_view->expand_all();

    show_all_children();
}

bool ProjectTree::on_double_click(GdkEventButton* event) {
    if (event->button == 1) {
        auto tree_selection = tree_view->get_selection();
        auto tree_iterator = tree_selection->get_selected();

        if (tree_iterator) {
            auto row = *tree_iterator;
            if (row.children().empty()) {
                Glib::ustring p = row[columns.filepath];
                parent->getEditor()->open_file(p.c_str());
                std::cout << "try open file: " << p << std::endl;
            } else {
                std::cout << "is a directory" << std::endl;
            }
        }
    }
    std::cout << "pressed: " << event->button << std::endl;

    return false;
}
