#include "ui_framework/MButton.hpp"

void click(GtkWidget *gtkWidget, MButton *btnptr)
{
    btnptr->HandleClick();
}

MButton::MButton(MWidget & parent, const char *label)
{
    gtkwidget = gtk_button_new_with_label (label);
    gtk_widget_set_size_request (gtkwidget, w, h);
    parent.AddChild(*this);
}

void MButton::OnClick(ClickHandler f)
{
    HandleClick = f;
    g_signal_connect(gtkwidget, "clicked", G_CALLBACK(click), this);
}