#ifndef __MTextBox_hpp__
#define __MTextBox_hpp__
#include "ui_framework/MWidget.hpp"
#include <functional>

typedef std::function<void(void)> ClickHandler;
class MTextBox : public MWidget
{
public:
    MTextBox(MWidget & parent);
    void SetText(const char*);
    std::string GetText();
private:
    int id = 0;
};

#endif