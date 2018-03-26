#include "Application.h"

#define PACKAGE_NAME "TimTex"

Application::Application(int &argc, char **&argv) : Gtk::Application(argc, argv) {
    Glib::set_application_name(PACKAGE_NAME);
}

Application::~Application() {
    delete mainWindow;
}

void Application::_on_activate() {
    if (mainWindow) {
        mainWindow->present();
    }
}

void Application::_on_startup() {
    mainWindow = new MainWindow();
    add_window(*mainWindow);
}

void Application::_on_open() {
    mainWindow->present();
}
