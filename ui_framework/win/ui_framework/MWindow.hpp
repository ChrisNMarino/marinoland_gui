#ifndef __MWindow_hpp__
#define __MWindow_hpp__
#include "ui_framework/MWidget.hpp"
#include <string>
#include <map>

class MButton;
class MWindow : public MWidget
{
public:
    MWindow();
    void Show();
    void SetTitle(const char *title);
    void SetDimensions(const int w, const int h);
    LRESULT OnWindowEvent(UINT message, WPARAM wParam, LPARAM lParam);
    void HandleButtonClicked(int id, MButton* button);

    std::map<int, MButton*> buttonClickHandlers;
private:
};

#endif