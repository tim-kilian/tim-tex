
#include <iostream>
#include <gtkmm/box.h>
#include <gtkmm/separator.h>
#include <gtkmm/alignment.h>
#include <gtkmm/scrolledwindow.h>
#include "MainWindow.h"
#include "MenuBar.h"

MainWindow::MainWindow() {
    set_default_size(500, 300);

    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

    vbox->pack_start(*(new MenuBar()), Gtk::PACK_SHRINK);
    vbox->add(*(new Gtk::Separator()));
    vbox->add(*create_breadcrumb_view());
    vbox->add(*(new Gtk::Separator()));
    vbox->pack_start(*create_main_view(), Gtk::PACK_EXPAND_WIDGET);
    vbox->add(*(new Gtk::Separator()));
    vbox->pack_end(*create_footer_view(), Gtk::PACK_SHRINK);

    add(*vbox);
    vbox->show_all();
}

Gtk::Box* MainWindow::create_breadcrumb_view() {
    auto hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
    hbox->set_border_width(10);

    breadcrumb = new Gtk::Label("Breadcrumb");
    hbox->pack_start(*breadcrumb, Gtk::PACK_SHRINK);

    return hbox;
}

Gtk::Box* MainWindow::create_main_view() {
    auto box = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);

    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
    auto hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);

    auto separator_project = new Gtk::Separator();
    separator_project->signal_drag_data_get().connect(sigc::mem_fun(*this, &MainWindow::on_button_drag_data_get));

    hbox->pack_start(*create_project_view());
    hbox->pack_start(*separator_project);
    hbox->pack_start(*create_editor_view(), Gtk::PACK_EXPAND_WIDGET);

    vbox->pack_start(*hbox, Gtk::PACK_EXPAND_WIDGET);
    vbox->add(*create_console_view());

    box->add(*vbox);
    box->add(*create_document_view());

    return box;
}

Gtk::Box* MainWindow::create_project_view() {
    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

    treeView = new Gtk::TreeView();
    auto cell = new Gtk::CellRendererText();
    treeView->append_column("Messages", *cell);
    vbox->pack_start(*(new Gtk::Label("Project")), Gtk::PACK_SHRINK);
    vbox->pack_start(*treeView, Gtk::PACK_EXPAND_WIDGET);

    return vbox;
}

Gtk::Box* MainWindow::create_editor_view() {
    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

    auto hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);

    hbox->pack_start(*create_line_number_view(100), Gtk::PACK_SHRINK);
    hbox->pack_start(*(new Gtk::Separator()), Gtk::PACK_SHRINK);

    auto scrolledTextView = new Gtk::ScrolledWindow();
    scrolledTextView->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_NEVER);
    scrolledTextView->add(*(new Gtk::TextView()));

    hbox->pack_start(*scrolledTextView, Gtk::PACK_EXPAND_WIDGET);
    auto textView2 = new Gtk::TextView();

    auto editorWindow = new Gtk::ScrolledWindow();
    editorWindow->set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
    editorWindow->add(*hbox);

    notebook = new Gtk::Notebook();
    notebook->append_page(*editorWindow, "First");
    notebook->append_page(*textView2, "Second");
    notebook->signal_switch_page().connect(sigc::mem_fun(*this, &MainWindow::on_switch_tab));

    vbox->pack_start(*notebook, Gtk::PACK_EXPAND_WIDGET);

    return vbox;
}


Gtk::Box* MainWindow::create_line_number_view(int lines) {
    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

    for (int i=1; i<=lines; i++) {
        auto alignment = new Gtk::Alignment(Gtk::ALIGN_END);
        alignment->add(*(new Gtk::Label(std::to_string(i))));
        vbox->pack_start(*alignment, Gtk::PACK_SHRINK);
    }

    return vbox;
}

Gtk::Box* MainWindow::create_console_view() {
    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

    return vbox;
}

Gtk::Box* MainWindow::create_document_view() {
    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

    return vbox;
}

Gtk::Box* MainWindow::create_footer_view() {
    auto hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);

    hbox->set_border_width(5);
    hbox->pack_start(*(new Gtk::Label("// Some Information")), Gtk::PACK_SHRINK);

    return hbox;
}

void MainWindow::on_switch_tab(Gtk::Widget* tab, int page) {

}

void MainWindow::on_button_drag_data_get(const Glib::RefPtr<Gdk::DragContext>& context, Gtk::SelectionData& selection_data, guint info, guint time) {
    std::cout << "hello world " << info << " " << time << std::endl;
}
