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

#define RUN(classname) \
void activate(GtkApplication *app, gpointer user_data); \
int main(int argc, char **argv) \
{ \
    classname app; \
    GtkApplication *gtkapp = gtk_application_new (app.appname.c_str(), G_APPLICATION_FLAGS_NONE); \
    g_signal_connect (gtkapp, "activate", G_CALLBACK (activate), (MApplication*)&app); \
    int status = g_application_run (G_APPLICATION (gtkapp), argc, argv); \
    g_object_unref (gtkapp); \
    return status; \
} \

#endif