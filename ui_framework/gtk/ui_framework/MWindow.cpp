#include "ui_framework/MWindow.hpp"

MWindow::MWindow(GtkApplication *app)
{
    gtkwidget = gtk_application_window_new (app);
    gtkcontainer = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(gtkwidget), gtkcontainer);
}

void MWindow::SetTitle(const char *title)
{
    gtk_window_set_title (GTK_WINDOW (gtkwidget), title);
}

void MWindow::SetDimensions(const int w, const int h)
{
    MWidget::SetDimensions(w, h);
    gtk_window_set_default_size (GTK_WINDOW (gtkwidget), w, h);
}

void MWindow::Show()
{
    gtk_widget_show_all (gtkwidget);
}

void MWindow::AddChild(MWidget & child) 
{
    gtk_fixed_put(GTK_FIXED(gtkcontainer), child.gtkwidget, child.GetLeft(), child.GetTop());
    //gtk_container_add(GTK_CONTAINER (gtkcontainer), child.gtkwidget);
}