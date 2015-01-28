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
GtkWidget* Gtk2Outputter::error_(NULL);
/*
GdkRGBA Gtk2Outputter::colorSuccess_ = {0.0, 1.0, 0.0, 1.0};
GdkRGBA Gtk2Outputter::colorFail_ = {1.0, 0.0, 0.0, 1.0};
GdkRGBA Gtk2Outputter::currentColor_ = Gtk2Outputter::colorSuccess_;
*/

Gtk2Outputter::Gtk2Outputter(int* argc, char*** argv) : /*window_(NULL), error_(NULL),*/table_(NULL), argc_(argc), argv_(argv) {
}

Gtk2Outputter::~Gtk2Outputter() {
}

void Gtk2Outputter::outputContents(std::string outputName,
        std::string contents) {

    if(contents == "success") {
        gtk_widget_hide_all(window_);
    }
    else {

    }

}

void Gtk2Outputter::initializeDevice() {
    gtk_init(argc_, argv_);

    createWindow();
    createTable();
    createErrorDialog();
    gtk_widget_show_all(window_);

    pthread_t threadId(0);

    if(threadId == 0) {
        pthread_create(&threadId, NULL, &Gtk2Outputter::run, NULL);
    }
}

////////////////////////////////////////////////////////////////////////////////
void Gtk2Outputter::createWindow() {
    window_ = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window_), "xfd");
    gtk_window_set_default_size(GTK_WINDOW(window_), width_, hight_);
    g_signal_connect(window_, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
}

void Gtk2Outputter::createTable() {
    table_ = gtk_table_new(2, 2, true);
    gtk_table_set_row_spacings(GTK_TABLE(table_), 2);
    gtk_table_set_col_spacings(GTK_TABLE(table_), 2);
}

void Gtk2Outputter::createErrorDialog() {
    error_ = gtk_button_new_with_label("Error");

    gtk_table_attach(GTK_TABLE(table_), error_, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 3, 3);
    gtk_container_add(GTK_CONTAINER(window_), table_);
    gtk_container_set_border_width(GTK_CONTAINER(window_), 15);
    g_signal_connect(error_, "clicked", G_CALLBACK(showError), (gpointer)window_);
}


void Gtk2Outputter::showError(GtkWidget* widget, gpointer data) {
    GtkWidget* dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(window_),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_QUESTION,
            GTK_BUTTONS_YES_NO,
            "");
    gtk_window_set_title(GTK_WINDOW(dialog), "Error");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void* Gtk2Outputter::run(void* pParameter) {
    gtk_main();
    return 0;
}
