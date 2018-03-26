#ifndef TIMTEX_APPLICATION_H
#define TIMTEX_APPLICATION_H


#include <gtkmm.h>
#include <gtkmm/application.h>
#include "MainWindow.h"

class Application : public Gtk::Application {
public:
    Application(int& argc, char**& argv);
    ~Application();

private:
    void on_activate() override { Gtk::Application::on_activate(); _on_activate(); }
    void _on_activate();

    void on_startup() override { Gtk::Application::on_startup(); _on_startup(); }
    void _on_startup();

    void on_open(const type_vec_files &files, const Glib::ustring & hint) override { _on_open(); }
    void _on_open();

    MainWindow* mainWindow = nullptr;
};


#endif
