#include "ui_framework/MWindow.hpp"

LRESULT CALLBACK MainWindowCallback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    MWindow *mWindow = (MWindow *)lParam;
    switch(message)
    {
    case WM_DESTROY:
        ::PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}

MWindow::MWindow()
{
    RegisterWindowClass("MainWindowClass", ::MainWindowCallback);
    hWnd = CreateWindow(
        "MainWindowClass",
        "",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        100, 100,
        NULL, NULL, hInstance, this);
}

void MWindow::SetTitle(const char *title)
{
    SetWindowText(hWnd, title);
}

void MWindow::SetDimensions(const int w, const int h)
{
    RECT rect;
    GetWindowRect(hWnd, &rect);
    SetWindowPos(hWnd, NULL, rect.left, rect.top , w, h, 0);
}

void MWindow::Show()
{
    ShowWindow(hWnd, SW_SHOW);

}