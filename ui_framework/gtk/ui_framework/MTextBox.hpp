#ifndef __MTextBox_hpp__
#define __MTextBox_hpp__
#include "ui_framework/MWidget.hpp"

typedef std::function<void(void)> ClickHandler;
class MTextBox : public MWidget
{
public:
    MTextBox(MWidget &parent);
    void SetText(const char *str);
    std::string GetText();
private:
};

#endif