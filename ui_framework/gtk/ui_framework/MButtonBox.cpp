#include "ui_framework/MButtonBox.hpp"

MButtonBox::MButtonBox(MWidget & parent)
{
    gtkwidget = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    parent.AddChild(*this);
}