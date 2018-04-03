
#ifndef TIMTEX_PROJECTTREE_H
#define TIMTEX_PROJECTTREE_H


#include <gtkmm/box.h>
#include <gtkmm/treeview.h>
#include <gtkmm/treestore.h>
#include "boost/filesystem.hpp"
#include "MainWindow.h"

using namespace boost::filesystem;

class ProjectTree : public Gtk::Box {

    class ProjectColumns : public Gtk::TreeModel::ColumnRecord {
    public:
        ProjectColumns() { add(name); add(filepath); }

        Gtk::TreeModelColumn<Glib::ustring> name;
        Gtk::TreeModelColumn<Glib::ustring> filepath;
    };

public:
    explicit ProjectTree(MainWindow* window);

    void open(const char* directory);

private:
    path project_path;
    MainWindow* parent;
    ProjectColumns columns;
    Gtk::TreeView* tree_view;
    Glib::RefPtr<Gtk::TreeStore> tree_model;

    bool on_double_click(GdkEventButton* event);
};


#endif
