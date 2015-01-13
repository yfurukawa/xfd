/*
 * Copyright
 *
 */
//#include <gtk/gtk.h>
#include <pthread.h>
#include "./GtkOutputter.h"

int GtkOutputter::width_(320);
int GtkOutputter::hight_(200);
GdkRGBA GtkOutputter::colorSuccess_ = {0.0, 1.0, 0.0, 1.0};
GdkRGBA GtkOutputter::colorFail_ = {1.0, 0.0, 0.0, 1.0};
GdkRGBA GtkOutputter::currentColor_ = GtkOutputter::colorSuccess_;

GtkOutputter::GtkOutputter(int* argc, char*** argv) : window_(NULL), canvas_(NULL), argc_(argc), argv_(argv) {
}

GtkOutputter::~GtkOutputter() {
}

void GtkOutputter::outputContents(std::string outputName,
        std::string contents) {

    if(contents == "success") {
        currentColor_ = colorSuccess_;
        gtk_widget_queue_draw(window_);
    }
    else {
        currentColor_ = colorFail_;
        gtk_widget_queue_draw(window_);
    }

}

void GtkOutputter::initializeDevice() {
    gtk_init(argc_, argv_);

    createWindow();
    createCanvas();
    gtk_widget_show_all(window_);

    pthread_t threadId(0);

    if(threadId == 0) {
        pthread_create(&threadId, NULL, &GtkOutputter::run, NULL);
    }
}

////////////////////////////////////////////////////////////////////////////////
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
    gdk_cairo_set_source_rgba(cr, &GtkOutputter::currentColor_);
    cairo_rectangle(cr, 0.0, 0.0, width_, hight_);
    cairo_fill(cr);

    return false;
}

void* GtkOutputter::run(void* pParameter) {
    gtk_main();
    return 0;
}