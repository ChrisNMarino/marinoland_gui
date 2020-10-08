#include "ui_framework/MButton.hpp"
#include "ui_framework/MButtonBox.hpp"

void click(GtkWidget *gtkWidget, MButton *btnptr)
{
    btnptr->HandleClick();
}

MButton::MButton(MButtonBox & parent, const char *label)
{
    gtkwidget = gtk_button_new_with_label (label);
    parent.AddChild(*this);
}

void MButton::OnClick(ClickHandler f)
{
    HandleClick = f;
    g_signal_connect(gtkwidget, "clicked", G_CALLBACK(click), this);
}