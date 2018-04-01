
#include <iostream>
#include <poppler-page-renderer.h>
#include "Preview.h"
#include <math.h>

Preview::Preview() {
    active_page = 0;

    document = poppler::document::load_from_file("/home/tim/LatexProjects/test/error.pdf");
}

void Preview::set_file(const char* path) {
    filepath = path;
    update();
}

void Preview::update() {
    document = poppler::document::load_from_file(filepath);
    if (document) {
        std::cout << "redraw document" << std::endl;
        queue_draw();
    } else {
        document = poppler::document::load_from_file("/home/tim/LatexProjects/test/error.pdf");
        std::cout << "redraw error" << std::endl;
    }
}

bool Preview::on_draw(const Cairo::RefPtr<Cairo::Context> &context) {
    poppler::page* page = document->create_page(active_page);

    auto image = poppler::page_renderer().render_page(page);

    auto data = reinterpret_cast<unsigned char*>(image.data());

    context->set_source(Cairo::ImageSurface::create(data, Cairo::FORMAT_ARGB32, image.width(), image.height(), image.bytes_per_row()), 0, 0);
    context->paint();

    return true;
}

void Preview::set_page(int page) {
    active_page = std::max(0, std::min(document->pages()-1, page));
    queue_draw();
}

void Preview::on_increase_page() {
    set_page(active_page + 1);
}

void Preview::on_decrease_page() {
    set_page(active_page - 1);
}
