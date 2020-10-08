#include "ui_framework/MButton.hpp"

/*
void click(GtkWidget *gtkWidget, MButton *btnptr)
{
    btnptr->HandleClick();
}
*/

MButton::MButton(const char *label)
{
    //gtkwidget = gtk_button_new_with_label (label);
}

void MButton::OnClick(ClickHandler f)
{
    HandleClick = f;
    //g_signal_connect(gtkwidget, "clicked", G_CALLBACK(click), this);
}