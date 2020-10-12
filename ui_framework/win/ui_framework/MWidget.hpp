#ifndef __MWidget_hpp__
#define __MWidget_hpp__
#include <windows.h>
#include <string>
#include <map>
#include <vector>
#include <functional>

class MButton;
typedef std::function<void(WNDCLASSEX&)> GetRegisterWndClassParams;
typedef std::function<void(CREATESTRUCT&)> GetCreateWndParams;
typedef std::function<int(UINT, WPARAM, LPARAM)> EventSpy;
class MWidget
{
public:
    void Close();
    static HINSTANCE hInstance;
    HWND hWnd = 0;
    
    HWND CreateHwnd(GetCreateWndParams createParams);
    HWND CreateCustomHwnd(GetRegisterWndClassParams regParams, GetCreateWndParams createParams);

    void AddEventSpy(EventSpy spy);

    virtual LRESULT OnWindowEvent(UINT message, WPARAM wParam, LPARAM lParam) {return 0; };
    std::vector<EventSpy> eventSpies;

protected:
    static std::map<std::string, int> registeredWindowClasses;

};

#endif