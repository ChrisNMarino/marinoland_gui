#include "ui_framework/MWindow.hpp"

MWindow::MWindow(GtkApplication *app)
{
    gtkwidget = gtk_application_window_new (app);
}

void MWindow::SetTitle(const char *title)
{
    gtk_window_set_title (GTK_WINDOW (gtkwidget), title);
}

void MWindow::SetDimensions(const int w, const int h)
{
    gtk_window_set_default_size (GTK_WINDOW (gtkwidget), w, h);
}

void MWindow::Show()
{
    gtk_widget_show_all (gtkwidget);
}