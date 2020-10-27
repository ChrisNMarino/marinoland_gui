#include "ui_framework/MButton.hpp"
#include <iostream>

void click(GtkWidget *gtkWidget, MButton *btnptr)
{
    btnptr->HandleClick();
}

MButton::MButton(MWidget & parent, const char *label)
{
    int w = GetWidth();
    int h = GetHeight();
    int x = GetLeft();
    int y = GetHeight();
    SetGtkWidget(gtk_button_new_with_label (label));
    parent.AddChild(*this);
    SetPosition(x, y);
    SetDimensions(w, h);
}

void MButton::OnClick(ClickHandler f)
{
    HandleClick = f;
    g_signal_connect(GetGtkWidget(), "clicked", G_CALLBACK(click), this);
}