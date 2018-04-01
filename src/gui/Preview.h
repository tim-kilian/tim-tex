
#ifndef TIMTEX_PREVIEW_H
#define TIMTEX_PREVIEW_H

#include <poppler-document.h>
#include <poppler-page.h>
#include <gtkmm/drawingarea.h>

class Preview : public Gtk::DrawingArea {

public:
    Preview();

    void set_file(const char* path);
    void set_page(int page);

    void on_increase_page();
    void on_decrease_page();

    void update();

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

private:
    const char* filepath;
    int active_page;
    poppler::document* document;
};


#endif
