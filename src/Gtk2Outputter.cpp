/*
 * Copyright
 *
*/
#include <gtk/gtk.h>
#include <pthread.h>
#include <iostream>
#include "./Gtk2Outputter.h"

/*
int Gtk2Outputter::width_(320);
int Gtk2Outputter::hight_(200);
GdkRGBA Gtk2Outputter::colorSuccess_ = {0.0, 1.0, 0.0, 1.0};
GdkRGBA Gtk2Outputter::colorFail_ = {1.0, 0.0, 0.0, 1.0};
GdkRGBA Gtk2Outputter::currentColor_ = Gtk2Outputter::colorSuccess_;
*/

Gtk2Outputter::Gtk2Outputter(int* argc, char*** argv) :/* window_(NULL), canvas_(NULL), */argc_(argc), argv_(argv) {
}

Gtk2Outputter::~Gtk2Outputter() {
}

void Gtk2Outputter::outputContents(std::string outputName,
        std::string contents) {

//    if(contents == "success") {
//        currentColor_ = colorSuccess_;
//        gtk_widget_queue_draw(window_);
//    }
//    else {
//        currentColor_ = colorFail_;
//        gtk_widget_queue_draw(window_);
//    }

}

void Gtk2Outputter::initializeDevice() {
//    gtk_init(argc_, argv_);
//
//    createWindow();
//    createCanvas();
//    gtk_widget_show_all(window_);
//
//    pthread_t threadId(0);
//
//    if(threadId == 0) {
//        pthread_create(&threadId, NULL, &Gtk2Outputter::run, NULL);
//    }
}

////////////////////////////////////////////////////////////////////////////////
void Gtk2Outputter::createWindow() {
//    window_ = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//    gtk_window_set_title(GTK_WINDOW(window_), "xfd");
//    g_signal_connect(window_, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
}

void Gtk2Outputter::createCanvas() {
//    canvas_ = gtk_drawing_area_new();
//    gtk_widget_set_size_request(canvas_, width_, hight_);
//    gtk_container_add(GTK_CONTAINER(window_), canvas_);
//    g_signal_connect(canvas_, "draw", G_CALLBACK(&Gtk2Outputter::draw_canvas), NULL);
}

/*
gboolean Gtk2Outputter::draw_canvas(GtkWidget* widget, cairo_t* cr,
        gpointer data) {
    gdk_cairo_set_source_rgba(cr, &Gtk2Outputter::currentColor_);
    cairo_rectangle(cr, 0.0, 0.0, width_, hight_);
    cairo_fill(cr);

    return false;
}
*/

void* Gtk2Outputter::run(void* pParameter) {
    std::cout << std::hex << pthread_self() << std::endl;
    gtk_main();
    return 0;
}
