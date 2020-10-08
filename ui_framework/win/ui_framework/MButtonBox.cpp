#include "ui_framework/MButtonBox.hpp"
#include "ui_framework/MButton.hpp"
#include <string>

LRESULT CALLBACK ButtonBoxCallback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    MButtonBox* mWindow = (MButtonBox*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
    switch (message)
    {
    case WM_CREATE:
    {
        CREATESTRUCT* create = (CREATESTRUCT*)lParam;
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LPARAM)create->lpCreateParams);
        break;
    }
    case WM_COMMAND:
        switch (HIWORD(wParam))
        {
        case BN_CLICKED:
        {
            int id = LOWORD(wParam);
            MButton* btn = mWindow->buttonClickHandlers[id];
            if (btn)
            {
                btn->HandleClick();
            }
			break;
        }
        }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}

void MButtonBox::HandleButtonClicked(int id, MButton* button) {
    buttonClickHandlers[id] = button;
}

MButtonBox::MButtonBox(MWidget &parent)
{
    RegisterWindowClass("ButtonBoxClass", ButtonBoxCallback);

    hWnd = CreateWindowEx(
        NULL,
        "ButtonBoxClass",
        "",
        WS_CHILD | WS_BORDER,
        0, 0,
        100, 100,
        parent.hWnd, NULL, hInstance, this);
    ShowWindow(hWnd, SW_SHOW);
}