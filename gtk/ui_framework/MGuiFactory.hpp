#ifndef __MGuiFactory_hpp__
#define __MGuiFactory_hpp__
#include <memory>
#include "ui_framework/MButton.hpp"
#include "ui_framework/MButtonBox.hpp"
#include "ui_framework/MWindow.hpp"

typedef std::shared_ptr<MButton> MButtonRef;
typedef std::shared_ptr<MButtonBox> MButtonBoxRef;
typedef std::shared_ptr<MWindow> MWindowRef;
class MApplication;

class MGuiFactory {
public:
    MGuiFactory(GtkApplication *app) {
        gtkapp = app;
    }
    MButtonRef button(const char *label) { return std::make_shared<MButton>(label); }
    MButtonBoxRef buttonBox() { return std::make_shared<MButtonBox>(); }
    MWindowRef window() { return std::make_shared<MWindow>(gtkapp); }
private:
    GtkApplication *gtkapp;
};

#endif