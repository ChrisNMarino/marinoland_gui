#include "ui_framework/MWidget.hpp"
#include <iostream>

HINSTANCE MWidget::hInstance = 0;
using namespace std;
map<string, int> MWidget::registeredWindowClasses;

LRESULT CALLBACK MainWindowCallback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    MWidget* mWindow = (MWidget*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
    switch (message)
    {
    case WM_CREATE:
    {
        CREATESTRUCT* create = (CREATESTRUCT*)lParam;
        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LPARAM)create->lpCreateParams);
        break;
    }
    }
    if (mWindow)
    {
        for (EventSpy spy : mWindow->eventSpies)
            spy(message, wParam, lParam);
        return mWindow->OnWindowEvent(message, wParam, lParam);
    }
    else
        return DefWindowProc(hWnd, message, wParam, lParam);
}

HWND MWidget::CreateCustomHwnd(GetRegisterWndClassParams regParams, GetCreateWndParams createParams)
{

    return CreateHwnd([&](CREATESTRUCT& create) {
        createParams(create);
        string className(create.lpszClass);
        if (!registeredWindowClasses[className])
        {
            WNDCLASSEX wndClass;
            wndClass.cbSize = sizeof(WNDCLASSEX);
            wndClass.style = CS_HREDRAW | CS_VREDRAW;
            wndClass.lpfnWndProc = MainWindowCallback;
            wndClass.cbClsExtra = 0;
            wndClass.cbWndExtra = 0;
            wndClass.hInstance = hInstance;
            wndClass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
            wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
            wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
            wndClass.lpszMenuName = NULL;
            wndClass.lpszClassName = create.lpszClass;
            wndClass.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
            regParams(wndClass);
            int result;
            if (!(result = ::RegisterClassEx(&wndClass)))
            {
                string msg = "Registration of class '";
                msg += create.lpszClass;
                msg += "' has failed";
                ::MessageBox(NULL, msg.c_str(), "RegisterClass failed", NULL);
            }
            registeredWindowClasses[className] = TRUE;
        }
	});
}

HWND MWidget::CreateHwnd(GetCreateWndParams getParams) 
{
    CREATESTRUCT create;
    create.dwExStyle = 0;
    create.lpszClass = "default";
    create.lpszName = "";
    create.style = WS_OVERLAPPEDWINDOW;
    create.x = 0;
    create.y = 0;
    create.cx = 100;
    create.cy = 100;
    create.hInstance = hInstance;
    create.hMenu = NULL;
    create.hwndParent = NULL;
    getParams(create);
    hWnd = CreateWindowEx(
        create.dwExStyle, create.lpszClass, create.lpszName,
        create.style, create.x, create.y, create.cx, create.cy,
        create.hwndParent, create.hMenu, create.hInstance, this);

    return hWnd;
}

void MWidget::AddEventSpy(EventSpy spy) {
    eventSpies.push_back(spy);
}

void MWidget::Close()
{
    DestroyWindow(hWnd);
}

