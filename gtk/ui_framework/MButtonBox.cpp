#include "ui_framework/MButtonBox.hpp"

MButtonBox::MButtonBox()
{
    gtkwidget = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
}