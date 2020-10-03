#include "ui_framework/MWidget.hpp"
#include <iostream>

void MWidget::AddChild(MWidget & child)
{
    gtk_container_add(GTK_CONTAINER (gtkwidget), child.gtkwidget);
}

void MWidget::Close()
{
    gtk_widget_destroy(gtkwidget);
}