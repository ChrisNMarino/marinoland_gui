#include "ui_framework/MWindow.hpp"
#include <iostream>

MWindow::MWindow(GtkApplication *app)
{
    SetGtkWidget(gtk_application_window_new (app));
    gtkcontainer = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(GetGtkWidget()), gtkcontainer);
}

void MWindow::SetTitle(const char *title)
{
    gtk_window_set_title (GTK_WINDOW (GetGtkWidget()), title);
}

void MWindow::SetDimensions(const int w, const int h)
{
    MWidget::SetDimensions(w, h);
    gtk_window_set_default_size (GTK_WINDOW (GetGtkWidget()), w, h);
}

void MWindow::GetClientRect(int & w, int & h)
{
    GtkAllocation allocation;
    gtk_widget_get_allocation(gtkcontainer, &allocation);
    w = allocation.width;
    h = allocation.height;
}

void MWindow::Show()
{
    gtk_widget_show_all (GetGtkWidget());
}

void MWindow::AddChild(MWidget & child) 
{
    child.SetParentContainer(GTK_CONTAINER(gtkcontainer));
    gtk_layout_put(GTK_LAYOUT(gtkcontainer), child.GetGtkWidget(), child.GetLeft(), child.GetTop());
}