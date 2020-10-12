#include "ui_framework/MWindow.hpp"
#include "ui_framework/MButton.hpp"

LRESULT MWindow::OnWindowEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
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
    CreateCustomHwnd(
        [](WNDCLASSEX & wndClass) {},
        [](CREATESTRUCT & create) {
            create.lpszClass = "MainWindowClass";
        });
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