
#include <iostream>
#include <gtkmm/box.h>
#include <gtkmm/separator.h>
#include <gtkmm/alignment.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/paned.h>
#include "MainWindow.h"
#include "MenuBar.h"

MainWindow::MainWindow() {
    set_default_size(500, 300);

    auto vbox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

    vbox->pack_start(*(new MenuBar()), Gtk::PACK_SHRINK);
    vbox->add(*(new Gtk::Separator()));
    vbox->add(*create_header_view());
    vbox->add(*(new Gtk::Separator()));
    vbox->pack_start(*create_main_view(), Gtk::PACK_EXPAND_WIDGET);
    vbox->add(*(new Gtk::Separator()));
    vbox->pack_end(*create_footer_view(), Gtk::PACK_SHRINK);

    add(*vbox);
    vbox->show_all();
}

Gtk::Box* MainWindow::create_header_view() {
    auto hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
    hbox->set_border_width(10);

    breadcrumb = new Gtk::Label("Project / Breadcrumb");
    hbox->pack_start(*breadcrumb, Gtk::PACK_SHRINK);

    return hbox;
}

Gtk::Box* MainWindow::create_main_view() {
    auto box = new Gtk::Box();
    auto paned = new Gtk::HPaned();

    auto vpaned = new Gtk::VPaned;

    auto hpaned = new Gtk::HPaned();

    hpaned->add1(*create_project_view());
    hpaned->add2(*create_editor_view());

    vpaned->add1(*hpaned);
    vpaned->add2(*create_console_view());

    paned->add1(*vpaned);
    paned->add2(*create_document_view());

    box->pack_start(*paned, Gtk::PACK_EXPAND_WIDGET);

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

    vbox->pack_start(*(new Gtk::Label("<_")));

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
