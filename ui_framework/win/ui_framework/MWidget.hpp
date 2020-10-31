#ifndef __MWidget_hpp__
#define __MWidget_hpp__
#include <windows.h>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <iostream>

class MButton;
typedef std::function<void(WNDCLASSEX&)> GetRegisterWndClassParams;
typedef std::function<void(CREATESTRUCT&)> GetCreateWndParams;
typedef std::function<void(UINT, WPARAM, LPARAM)> EventSpy;
typedef std::function<void(int, int)> ResizeHandler;
class MWidget
{
public:
    void Close();
    static HINSTANCE hInstance;
    HWND hWnd = 0;
    
    HWND CreateHwnd(GetCreateWndParams createParams);
    HWND CreateCustomHwnd(GetRegisterWndClassParams regParams, GetCreateWndParams createParams);

    void AddEventSpy(EventSpy spy);
    void OnResize(ResizeHandler f)
    {
		AddEventSpy([f](UINT msg, WPARAM wParam, LPARAM lParam) {
			if (msg == WM_SIZE) f(LOWORD(lParam), HIWORD(lParam));
		});
    }

    void GetClientRect(int& width, int& height) {
        RECT rect;
        ::GetClientRect(hWnd, &rect);
        width = rect.right;
        height = rect.bottom;
    }

    virtual void SetDimensions(int w, int h) {
        SetWindowPos(hWnd, 0, 0, 0, w, h, SWP_NOZORDER | SWP_NOMOVE);
    }
    virtual void SetPosition(int x, int y) {
        SetWindowPos(hWnd, 0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
    }
    virtual LRESULT OnWindowEvent(UINT message, WPARAM wParam, LPARAM lParam) {return 0; };
    std::vector<EventSpy> eventSpies;

protected:
    static std::map<std::string, int> registeredWindowClasses;
};

#endif