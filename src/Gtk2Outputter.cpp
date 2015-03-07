/*
 * Copyright
 *
*/
#include <gtk/gtk.h>
#include <pthread.h>
#include <iostream>
#include "./Gtk2Outputter.h"


int Gtk2Outputter::width_(320);
int Gtk2Outputter::hight_(200);
GtkWidget* Gtk2Outputter::window_(NULL);
GdkColor Gtk2Outputter::bgColor_ = {255, 0, 0};

Gtk2Outputter::Gtk2Outputter(int* argc, char*** argv) : argc_(argc), argv_(argv) {
}

Gtk2Outputter::~Gtk2Outputter() {
}

void Gtk2Outputter::outputContents(std::string outputName,
        std::string contents) {

    if(contents == "success") {
        gtk_widget_hide(window_);
    }
    else {
        gtk_widget_show(window_);
    }

}

void Gtk2Outputter::initializeDevice() {
    gtk_init(argc_, argv_);
    createWindow();
    gtk_widget_show_all(window_);

    pthread_t threadId(0);

    if(threadId == 0) {
        pthread_create(&threadId, NULL, &Gtk2Outputter::run, NULL);
    }
}

////////////////////////////////////////////////////////////////////////////////
void Gtk2Outputter::createWindow() {
    gdk_color_parse("red", &bgColor_);

    window_ = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_widget_modify_bg(window_, GTK_STATE_NORMAL, &bgColor_);
    gtk_window_set_title(GTK_WINDOW(window_), "xfd");
    gtk_window_set_default_size(GTK_WINDOW(window_), width_, hight_);
    g_signal_connect(window_, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
}

void* Gtk2Outputter::run(void* pParameter) {
    gtk_main();
    return 0;
}
