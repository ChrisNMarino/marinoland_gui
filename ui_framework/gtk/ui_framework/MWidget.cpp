#include "ui_framework/MWidget.hpp"
#include <iostream>

HINSTANCE MWidget::hInstance = 0;

void MWidget::AddChild(MWidget & child)
{
    gtk_container_add(GTK_CONTAINER (gtkwidget), child.gtkwidget);
}

void MWidget::Close()
{
    gtk_widget_destroy(gtkwidget);
}