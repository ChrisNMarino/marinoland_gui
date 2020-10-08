#ifndef __MApplication_hpp__
#define __MApplication_hpp__

#include <string>
#include <iostream>
#include <functional>
#include "ui_framework/MGuiFactory.hpp"

class MApplication
{
public:
    MApplication(const char *appname);
    virtual void Ready(MGuiFactory *gui) = 0;
    std::string appname;
private:
};

#define RUN(classname) int WINAPI WinMain( \
    _In_ HINSTANCE hInstance, \
    _In_opt_ HINSTANCE hPrevInstance, \
    _In_ LPSTR lpCmdLine, \
    _In_ int nCmdShow \
) { \
    classname app; \
    MGuiFactory guifactory(hInstance); \
    app.Ready(&guifactory); \
    MSG msg; \
    while (GetMessage(&msg, NULL, 0, 0)) \
    { \
        TranslateMessage(&msg); \
        DispatchMessage(&msg); \
    } \
    return 0; \
}

#endif