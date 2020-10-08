#ifndef __MWidget_hpp__
#define __MWidget_hpp__
#include <windows.h>
#include <string>

class MWidget
{
public:
    void Close();
    static HINSTANCE hInstance;
    HWND hWnd;
protected:
    int RegisterWindowClass(
        LPCSTR className, WNDPROC wndProc
    );

};

#endif