#include <iostream>
#include <gtkmm/separatormenuitem.h>
#include "MenuBar.h"

MenuBar::MenuBar(MainWindow* window) : parent(window) {
    append(*create_menu_file());
    append(*create_menu_edit());
    append(*create_menu_view());
    append(*create_menu_document());
    append(*create_menu_vcs());
    append(*create_menu_help());
}

Gtk::MenuItem* MenuBar::create_menu_file() {
    menu_file = new Gtk::Menu();

    Gtk::MenuItem* item_file = new Gtk::MenuItem("File");
    item_file->set_submenu(*menu_file);

    Gtk::MenuItem* item_file_new = new Gtk::MenuItem("New");
    item_file_new->signal_activate().connect([] { std::cout << "New" << std::endl; });
    menu_file->append(*item_file_new);

    Gtk::MenuItem* item_file_open = new Gtk::MenuItem("Open");
    item_file_open->signal_activate().connect([] { std::cout << "Open" << std::endl; });
    menu_file->append(*item_file_open);

    menu_file->append(*(new Gtk::SeparatorMenuItem));

    Gtk::MenuItem* item_file_save = new Gtk::MenuItem("Save");
    item_file_save->signal_activate().connect([] { std::cout << "Save" << std::endl; });
    menu_file->append(*item_file_save);

    Gtk::MenuItem* item_file_save_as = new Gtk::MenuItem("Save as");
    item_file_save_as->signal_activate().connect([] { std::cout << "Save as" << std::endl; });
    menu_file->append(*item_file_save_as);

    menu_file->append(*(new Gtk::SeparatorMenuItem));

    Gtk::MenuItem* item_file_close = new Gtk::MenuItem("Close");
    item_file_close->signal_activate().connect([] { std::cout << "Close" << std::endl; });
    menu_file->append(*item_file_close);

    return item_file;
}

Gtk::MenuItem *MenuBar::create_menu_edit() {
    menu_edit = new Gtk::Menu();

    Gtk::MenuItem* item_edit = new Gtk::MenuItem("Edit");
    item_edit->set_submenu(*menu_edit);

    Gtk::MenuItem* item_edit_undo = new Gtk::MenuItem("Undo");
    item_edit_undo->signal_activate().connect([] { std::cout << "Undo" << std::endl; });
    menu_edit->append(*item_edit_undo);

    Gtk::MenuItem* item_edit_redo = new Gtk::MenuItem("Redo");
    item_edit_redo->signal_activate().connect([] { std::cout << "Redo" << std::endl; });
    menu_edit->append(*item_edit_redo);

    menu_edit->append(*(new Gtk::SeparatorMenuItem));

    Gtk::MenuItem* item_edit_cut = new Gtk::MenuItem("Cut");
    item_edit_cut->signal_activate().connect([] { std::cout << "Cut" << std::endl; });
    menu_edit->append(*item_edit_cut);

    Gtk::MenuItem* item_edit_copy = new Gtk::MenuItem("Copy");
    item_edit_copy->signal_activate().connect([] { std::cout << "Copy" << std::endl; });
    menu_edit->append(*item_edit_copy);

    Gtk::MenuItem* item_edit_paste = new Gtk::MenuItem("Paste");
    item_edit_paste->signal_activate().connect([] { std::cout << "Paste" << std::endl; });
    menu_edit->append(*item_edit_paste);

    return item_edit;
}

Gtk::MenuItem *MenuBar::create_menu_view() {
    menu_view = new Gtk::Menu();

    Gtk::MenuItem* item_view = new Gtk::MenuItem("View");
    item_view->set_submenu(*menu_view);

    Gtk::MenuItem* item_view_prev = new Gtk::MenuItem("Previous page");
    item_view_prev->signal_activate().connect(sigc::mem_fun(parent->getPreview(), &Preview::on_decrease_page));
    menu_view->append(*item_view_prev);

    Gtk::MenuItem* item_view_next = new Gtk::MenuItem("Next page");
    item_view_next->signal_activate().connect(sigc::mem_fun(parent->getPreview(), &Preview::on_increase_page));
    menu_view->append(*item_view_next);

    menu_view->append(*(new Gtk::SeparatorMenuItem));

    return item_view;
}

Gtk::MenuItem* MenuBar::create_menu_document() {
    menu_document = new Gtk::Menu();

    Gtk::MenuItem* item_document = new Gtk::MenuItem("Document");
    item_document->set_submenu(*menu_document);

    Gtk::MenuItem* item_document_compile = new Gtk::MenuItem("Compile");
    item_document_compile->signal_activate().connect([] { std::cout << "Compile" << std::endl; });
    menu_document->append(*item_document_compile);

    return item_document;
}

Gtk::MenuItem* MenuBar::create_menu_vcs() {
    menu_vcs = new Gtk::Menu();

    Gtk::MenuItem* item_vcs = new Gtk::MenuItem("VCS");
    item_vcs->set_submenu(*menu_vcs);

    Gtk::MenuItem* item_vcs_push = new Gtk::MenuItem("Push");
    item_vcs_push->signal_activate().connect([] { std::cout << "Push" << std::endl; });
    menu_vcs->append(*item_vcs_push);

    return item_vcs;
}

Gtk::MenuItem *MenuBar::create_menu_help() {
    menu_help = new Gtk::Menu();

    Gtk::MenuItem* item_help = new Gtk::MenuItem("Help");
    item_help->set_submenu(*menu_help);

    // menu_help->append(*(new Gtk::SeparatorMenuItem));

    Gtk::MenuItem* item_help_about = new Gtk::MenuItem("About");
    item_help_about->signal_activate().connect([] { std::cout << "About" << std::endl; });
    menu_help->append(*item_help_about);

    return item_help;
}

void MenuBar::on_next_page() {
    // parent->getPreview()->increase_page();
}
