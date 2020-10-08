#ifndef __MButton_hpp__
#define __MButton_hpp__
#include "ui_framework/MWidget.hpp"
#include <functional>

typedef std::function<void(void)> ClickHandler;
class MButtonBox;
class MButton : public MWidget
{
public:
    MButton(MButtonBox &parent, const char *label);
    void OnClick(ClickHandler f);
    ClickHandler HandleClick = [](){};
private:
};

#endif