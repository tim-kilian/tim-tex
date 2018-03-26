//
// Created by tim on 3/27/18.
//

#include <gtkmm/treeview.h>
#include "ProjectTree.h"

ProjectTree::ProjectTree() {
    auto treeView = new Gtk::TreeView();
    auto cell = new Gtk::CellRendererText();
    treeView->append_column("Messages", *cell);
    pack_start(*(new Gtk::Label("Project")), Gtk::PACK_SHRINK);
    pack_start(*treeView, Gtk::PACK_EXPAND_WIDGET);
}
