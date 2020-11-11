#ifndef __MGuiFactory_hpp__
#define __MGuiFactory_hpp__
#include <memory>
#include "ui_framework/MTextBox.hpp"
#include "ui_framework/MButton.hpp"
#include "ui_framework/MButtonBox.hpp"
#include "ui_framework/MWindow.hpp"

typedef std::shared_ptr<MButton> MButtonRef;
typedef std::shared_ptr<MButtonBox> MButtonBoxRef;
typedef std::shared_ptr<MTextBox> MTextBoxRef;
typedef std::shared_ptr<MWindow> MWindowRef;
class MApplication;

class MGuiFactory {
public:
    MGuiFactory(GtkApplication *app) {
        gtkapp = app;
    }
    MTextBoxRef textBox(MWidget & parent) { return std::make_shared<MTextBox>(parent); }
    MButtonRef button(MWidget & parent, const char *label) { return std::make_shared<MButton>(parent, label); }
    MButtonBoxRef buttonBox(MWidget &parent) { return std::make_shared<MButtonBox>(parent); }
    MWindowRef window() { return std::make_shared<MWindow>(gtkapp); }
    void messageBox(const char *title, const char *msg);
    void messageBox(MWindow &parent, const char *title, const char *msg);
private:
    GtkApplication *gtkapp;
};

#endif