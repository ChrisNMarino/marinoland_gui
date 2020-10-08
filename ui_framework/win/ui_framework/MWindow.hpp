#ifndef __MWindow_hpp__
#define __MWindow_hpp__
#include "ui_framework/MWidget.hpp"
#include <string>

class MWindow : public MWidget
{
public:
    MWindow();
    void Show();
    void SetTitle(const char *title);
    void SetDimensions(const int w, const int h);
private:
};

#endif