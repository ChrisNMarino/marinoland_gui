#include "ui_framework/MButtonBox.hpp"
#include "ui_framework/MButton.hpp"
#include <string>

LRESULT MButtonBox::OnWindowEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
    //switch (message)
    //{
    //default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    //    break;
    //}
    //return 0;
}


MButtonBox::MButtonBox(MWidget &parent)
{
    CreateCustomHwnd(
        [](WNDCLASSEX& wndClass) {},
        [&](CREATESTRUCT& create) {
            create.lpszClass = "ButtonBoxClass";
            create.style = WS_CHILD | WS_BORDER;
            create.hwndParent = parent.hWnd;

        });

    ShowWindow(hWnd, SW_SHOW);
}