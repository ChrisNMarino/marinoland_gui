#include "ui_framework/MWidget.hpp"
#include <iostream>

void resize(GtkWidget *gtkWidget, GdkRectangle *size, MWidget *_this)
{
    _this->w = size->width;
    _this->h = size->height;
    _this->HandleResize(size->width, size->height);
}

void MWidget::SetGtkWidget(GtkWidget *widget)
{
    gtkwidget = widget;
    g_signal_connect(gtkwidget, "size-allocate", G_CALLBACK(resize), this);
}

void MWidget::AddChild(MWidget & child)
{
    gtk_container_add(GTK_CONTAINER (gtkwidget), child.gtkwidget);
}

void MWidget::GetClientRect(int & w, int & h)
{
    w = this->w;
    h = this->h;
}

void MWidget::Close()
{
    gtk_widget_destroy(gtkwidget);
}

void MWidget::OnResize(ResizeHandler f)
{
    HandleResize = f;
}