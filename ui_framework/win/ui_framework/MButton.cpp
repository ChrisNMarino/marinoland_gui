#include "ui_framework/MButton.hpp"
#include "ui_framework/MButtonBox.hpp"


MButton::MButton(MWidget & parent, const char *label)
{
    static int btnCounter = 1000;
    btnCounter++;
    this->id = btnCounter;
    CreateHwnd([&](CREATESTRUCT& create) {
        create.lpszClass = "BUTTON";
        create.lpszName = label;
        create.style = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON;
        create.hwndParent = parent.hWnd;
        create.hMenu = (HMENU)btnCounter;
	});
    ShowWindow(hWnd, SW_SHOW);
    parent.AddEventSpy([&](UINT message, WPARAM wParam, LPARAM lParam) {
        if (message == WM_COMMAND && HIWORD(wParam) == BN_CLICKED && id == LOWORD(wParam))
            HandleClick();
        return 1;
	});
}

void MButton::OnClick(ClickHandler f)
{
    HandleClick = f;
}