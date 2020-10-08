#include "ui_framework/MApplication.hpp"
#include <iostream>

void activate(GtkApplication *app, gpointer user_data) {
    MGuiFactory guifactory(app);
    ((MApplication*)user_data)->Ready(&guifactory);
}

MApplication::MApplication(const char *appname) {
    this->appname = appname;
}
