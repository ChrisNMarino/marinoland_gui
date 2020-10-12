#ifndef __MButtonBox_hpp__
#define __MButtonBox_hpp__
#include "ui_framework/MWidget.hpp"
#include <map>

class MButton;
class MButtonBox : public MWidget
{
public:
    MButtonBox(MWidget & parent);
    LRESULT OnWindowEvent(UINT message, WPARAM wParam, LPARAM lParam);
private:
};

#endif