/*
 * Copyright
 *
 */
#include <gtk/gtk.h>
#include "./GtkOutputter.h"

int GtkOutputter::width_(320);
int GtkOutputter::hight_(200);
GtkOutputter::GtkOutputter(int* argc, char*** argv) : window_(NULL), canvas_(NULL) {
    initializeDevice(argc, argv);
}

GtkOutputter::~GtkOutputter() {
}

void GtkOutputter::outputContents(std::string outputName,
        std::string contents) {
}

////////////////////////////////////////////////////////////////////////////////
void GtkOutputter::initializeDevice(int* argc, char*** argv) {
    gtk_init(argc, argv);

    createWindow();
    createCanvas();
    gtk_widget_show_all(window_);
    gtk_main();
}

void GtkOutputter::createWindow() {
    window_ = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window_), "xfd");
    g_signal_connect(window_, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
}

void GtkOutputter::createCanvas() {
    canvas_ = gtk_drawing_area_new();
    gtk_widget_set_size_request(canvas_, width_, hight_);
    gtk_container_add(GTK_CONTAINER(window_), canvas_);
    g_signal_connect(canvas_, "draw", G_CALLBACK(&GtkOutputter::draw_canvas), NULL);
}

gboolean GtkOutputter::draw_canvas(GtkWidget* widget, cairo_t* cr,
        gpointer data) {
        GdkRGBA colorSuccess = {0.0, 1.0, 0.0, 1.0};
//        GdkRGBA colorFail = {1.0, 0.0, 0.0, 1.0};
    gdk_cairo_set_source_rgba(cr, &colorSuccess);
    cairo_rectangle(cr, 0.0, 0.0, width_, hight_);
    cairo_fill(cr);

    return false;
}
