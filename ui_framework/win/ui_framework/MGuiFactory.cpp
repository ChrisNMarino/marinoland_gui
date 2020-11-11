#include <ui_framework/MGuiFactory.hpp>


void msgBox(HWND parent, const char *title, const char *msg)
{
    MessageBox(parent, msg, title, MB_OK);
}

void MGuiFactory::messageBox(MWindow &parent, const char *title, const char *msg)
{
    msgBox(parent.hWnd, title, msg);
}

void MGuiFactory::messageBox(const char *title, const char *msg)
{
    msgBox(NULL, title, msg);
}