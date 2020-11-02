#include "ui_framework/MTextBox.hpp"


MTextBox::MTextBox(MWidget & parent)
{
    static int editCounter = 1100;
    editCounter++;
    this->id = editCounter;
    CreateHwnd([&](CREATESTRUCT& create) {
        create.lpszClass = "EDIT";
        //create.lpszName = label;
        create.style = WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER;
        create.hwndParent = parent.hWnd;
        create.hMenu = (HMENU)editCounter;
	});
    ShowWindow(hWnd, SW_SHOW);
}

void MTextBox::SetText(const char *text)
{
    SetWindowText(hWnd, text);
}

std::string MTextBox::GetText()
{
    const int len = GetWindowTextLength(hWnd)+1;
    std::string ret(len, ' ');
	GetWindowText(hWnd, (char*)ret.c_str(), len);
    return ret;
}
