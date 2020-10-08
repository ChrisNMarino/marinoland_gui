#include "ui_framework/MWidget.hpp"
#include <iostream>

HINSTANCE MWidget::hInstance = 0;

void MWidget::Close()
{
    DestroyWindow(hWnd);
}


int MWidget::RegisterWindowClass(
    LPCSTR className, WNDPROC wndProc)
{
    WNDCLASSEX wndClass;
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style          = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc    = wndProc;
    wndClass.cbClsExtra     = 0;
    wndClass.cbWndExtra     = 0;
    wndClass.hInstance      = MWidget::hInstance;
    wndClass.hIcon          = LoadIcon(hInstance, IDI_APPLICATION);
    wndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wndClass.lpszMenuName   = NULL;
    wndClass.lpszClassName  = className;
    wndClass.hIconSm        = LoadIcon(wndClass.hInstance, IDI_APPLICATION);

    int result;
    if(!(result = ::RegisterClassEx(&wndClass)))
    {
        std::string msg = "Registration of class '";
        msg += className;
        msg += "' has failed";
        ::MessageBox(NULL, msg.c_str(), "RegisterClass failed", NULL);
    }
    return result;
}