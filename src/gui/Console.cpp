//
// Created by tim on 3/27/18.
//

#include <gtkmm/label.h>
#include "Console.h"

Console::Console() {
    add(*(new Gtk::Label("<_")));
}
