#include "ui_framework/MButton.hpp"
#include "ui_framework/MButtonBox.hpp"

/*
void click(GtkWidget *gtkWidget, MButton *btnptr)
{
    btnptr->HandleClick();
}
*/


MButton::MButton(MButtonBox & parent, const char *label)
{
    static int btnCounter = 1000;
    btnCounter++;
    hWnd = CreateWindow(
        "BUTTON",
        label,
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        0, 0,
        100, 100,
        parent.hWnd, (HMENU)btnCounter, hInstance, this);
    ShowWindow(hWnd, SW_SHOW);
    parent.HandleButtonClicked(btnCounter, this);
}

void MButton::OnClick(ClickHandler f)
{
    HandleClick = f;
//    g_signal_connect(gtkwidget, "clicked", G_CALLBACK(click), this);
}