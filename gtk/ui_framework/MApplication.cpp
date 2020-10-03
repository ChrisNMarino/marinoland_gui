#include "ui_framework/MApplication.hpp"
#include <iostream>

MApplication *g_main;
static void activate(GtkApplication *app, gpointer user_data) {
    MGuiFactory guifactory(app);
    g_main->Ready(&guifactory);
}

MApplication::MApplication(const char *appname) {
    this->appname = appname;
    g_main = this;
}

int main(int argc, char **argv)
{
    GtkApplication *gtkapp = gtk_application_new (g_main->appname.c_str(), G_APPLICATION_FLAGS_NONE);
    g_signal_connect (gtkapp, "activate", G_CALLBACK (activate), 0);
    int status = g_application_run (G_APPLICATION (gtkapp), argc, argv);
    g_object_unref (gtkapp);
    return status;
}

